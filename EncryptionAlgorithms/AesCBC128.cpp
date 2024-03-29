/**
 * @file    AesCBC128.cpp
 * @brief   Definition of Aes CBC 128 bits algorithm.
 *
 * Copyright (c) 2020-forever Vlad Rogozin (vlad.rogozin@bhcc.edu)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "AesCBC128.h"
#include "_private/AesDeclarations.h"

using namespace Red::Aes;

// Base definitions.
#define AES_256 0
#define Nk      4
#define Nr      10
#define KEY_EXP_SIZE 176

// Object for encryption/decryption.
struct AES_ctx_CBC_128 {
    uint8_t RoundKey[KEY_EXP_SIZE];
    uint8_t Iv[BLOCK_BYTES_LENGTH];
};

inline static void KeyExpansion(uint8_t *RoundKey, const uint8_t *Key) {
    unsigned i, j, k;
    uint8_t tempa[4];

    for (i = 0; i < Nk; ++i) {
        RoundKey[(i * 4) + 0] = Key[(i * 4) + 0];
        RoundKey[(i * 4) + 1] = Key[(i * 4) + 1];
        RoundKey[(i * 4) + 2] = Key[(i * 4) + 2];
        RoundKey[(i * 4) + 3] = Key[(i * 4) + 3];
    }

    for (i = Nk; i < Nb * (Nr + 1); ++i) {
        {
            k = (i - 1) * 4;
            tempa[0]=RoundKey[k + 0];
            tempa[1]=RoundKey[k + 1];
            tempa[2]=RoundKey[k + 2];
            tempa[3]=RoundKey[k + 3];
        }

        if (i % Nk == 0) {
            {
                const uint8_t u8tmp = tempa[0];
                tempa[0] = tempa[1];
                tempa[1] = tempa[2];
                tempa[2] = tempa[3];
                tempa[3] = u8tmp;
            }

            {
                tempa[0] = getSBoxValue(tempa[0]);
                tempa[1] = getSBoxValue(tempa[1]);
                tempa[2] = getSBoxValue(tempa[2]);
                tempa[3] = getSBoxValue(tempa[3]);
            }

            tempa[0] = tempa[0] ^ Rcon[i/Nk];
        }

        #if AES_256 == 1
        if (i % Nk == 4) {
            {
                tempa[0] = getSBoxValue(tempa[0]);
                tempa[1] = getSBoxValue(tempa[1]);
                tempa[2] = getSBoxValue(tempa[2]);
                tempa[3] = getSBoxValue(tempa[3]);
            }
        }
        #endif

        j = i * 4; k=(i - Nk) * 4;
        RoundKey[j + 0] = RoundKey[k + 0] ^ tempa[0];
        RoundKey[j + 1] = RoundKey[k + 1] ^ tempa[1];
        RoundKey[j + 2] = RoundKey[k + 2] ^ tempa[2];
        RoundKey[j + 3] = RoundKey[k + 3] ^ tempa[3];
    }
}

// Key expansion operation.
inline static void AES_init_ctx_iv(struct AES_ctx_CBC_128 *ctx, const uint8_t *key, const uint8_t *iv) {
    KeyExpansion(ctx->RoundKey, key);
    memcpy(ctx->Iv, iv, BLOCK_BYTES_LENGTH);
}

inline static void Cipher(state_t *state, const uint8_t *RoundKey) {
    uint8_t round = 0;

    AddRoundKey(0, state, RoundKey);

    for (round = 1; ; ++round) {
        SubBytes(state);
        ShiftRows(state);

        if (round == Nr) {
            break;
        }

        MixColumns(state);
        AddRoundKey(round, state, RoundKey);
    }

    AddRoundKey(Nr, state, RoundKey);
}

inline static void InvCipher(state_t *state, const uint8_t *RoundKey) {
    uint8_t round = 0;

    AddRoundKey(Nr, state, RoundKey);

    for (round = (Nr - 1); ; --round) {
        InvShiftRows(state);
        InvSubBytes(state);
        AddRoundKey(round, state, RoundKey);

        if (round == 0) {
            break;
        }

        InvMixColumns(state);
    }
}

// Encrypt operation.
inline static void AES_CBC_encrypt_buffer(struct AES_ctx_CBC_128 *ctx, uint8_t *buf, uint32_t length) {
    uintptr_t i;
    uint8_t *Iv = ctx->Iv;

    for (i = 0; i < length; i += BLOCK_BYTES_LENGTH) {
        XorWithIv(buf, Iv);
        Cipher((state_t *) buf, ctx->RoundKey);
        Iv = buf;
        buf += BLOCK_BYTES_LENGTH;
    }

    memcpy(ctx->Iv, Iv, BLOCK_BYTES_LENGTH);
}

// Decrypt operation.
inline static void AES_CBC_decrypt_buffer(struct AES_ctx_CBC_128 *ctx, uint8_t *buf,  uint32_t length) {
    uintptr_t i;
    uint8_t storeNextIv[BLOCK_BYTES_LENGTH];

    for (i = 0; i < length; i += BLOCK_BYTES_LENGTH) {
        memcpy(storeNextIv, buf, BLOCK_BYTES_LENGTH);
        InvCipher((state_t *) buf, ctx->RoundKey);
        XorWithIv(buf, ctx->Iv);
        memcpy(ctx->Iv, storeNextIv, BLOCK_BYTES_LENGTH);
        buf += BLOCK_BYTES_LENGTH;
    }
}

/**
 * @brief Red::EncryptAesCBC128
 *
 * @param in    String to encrypt
 * @param key   Private key
 * @param iv    Initialization vector
 *
 * @return Encrypted string
 */
std::string * Red::EncryptAesCBC128(const std::string& in, const std::string_view key,
                                                           const std::string_view iv) {
    std::string *Encrypted = new std::string;

    unsigned long long int InLen = in.length();

    // Getting num of blocks.
    unsigned long long int NumOfBlocks = 1;

    if (InLen > BLOCK_BYTES_LENGTH) {
        NumOfBlocks = InLen / BLOCK_BYTES_LENGTH;

        if (InLen % BLOCK_BYTES_LENGTH != 0) {
            NumOfBlocks++;
        }
    }

    // Block operations.
    for (unsigned long long int CurrentBlock = 1; CurrentBlock <= NumOfBlocks; CurrentBlock++) {
        std::string Block = "";

        // Getting a block of information.
        for (unsigned long long int g = 0; g < BLOCK_BYTES_LENGTH; g++) {
            Block.push_back(in[BLOCK_BYTES_LENGTH * (CurrentBlock - 1) + g]);
        }

        // Padding.
        if (Block.length() != BLOCK_BYTES_LENGTH) {
            PaddingNulls(Block, Block.length(), BLOCK_BYTES_LENGTH);
        }

        // Encrypting.
        AES_ctx_CBC_128 ctx;

        AES_init_ctx_iv(&ctx, (const uint8_t *) key.data(), (const uint8_t *) iv.data());
        AES_CBC_encrypt_buffer(&ctx, (uint8_t *) Block.data(), Block.length());

        Encrypted->append(Block);
    }

    return Encrypted;
}

/**
 * @brief Red::DecryptAesCBC128
 *
 * @param in    String to decrypt
 * @param key   Private key
 * @param iv    Initialization vector
 *
 * @return Decrypted string
 */
std::string * Red::DecryptAesCBC128(const std::string& in, const std::string_view key,
                                                           const std::string_view iv) {
    std::string *Decrypted = new std::string;

    unsigned long long int InLen = in.length();

    // Getting num of blocks.
    unsigned long long int NumOfBlocks = 1;

    if (InLen > BLOCK_BYTES_LENGTH) {
        NumOfBlocks = InLen / BLOCK_BYTES_LENGTH;

        if (InLen % BLOCK_BYTES_LENGTH != 0) {
            NumOfBlocks++;
        }
    }

    // Block operations.
    for (unsigned long long int CurrentBlock = 1; CurrentBlock <= NumOfBlocks; CurrentBlock++) {
        std::string Block = "";

        // Getting a block of information.
        for (unsigned long long int g = 0; g < BLOCK_BYTES_LENGTH; g++) {
            Block.push_back(in[BLOCK_BYTES_LENGTH * (CurrentBlock - 1) + g]);
        }

        // Decrypting.
        AES_ctx_CBC_128 ctx;

        AES_init_ctx_iv(&ctx, (const uint8_t *) key.data(), (const uint8_t *) iv.data());
        AES_CBC_decrypt_buffer(&ctx, (uint8_t *) Block.data(), Block.length());

        Decrypted->append(Block);
    }

    return Decrypted;
}

#undef AES_256
#undef Nk
#undef Nr
#undef KEY_EXP_SIZE

