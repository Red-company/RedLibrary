/**
 * @file    rcrypt.h
 * @brief   rcrypt is a lib which is used to encrypt/hash information like passwords.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_RCRYPT_H
#define RED_RCRYPT_H

// System libs.
#include <string>

// RedLibrary.
#include "ResECB512.h"
#include "ResECB1024.h"
#include "ResECB1536.h"
#include "../HashFunctions/Sha256.h"

// Version.
#define REDRCRYPT_VERSION "1.0"

namespace Red {
    //
    // Rcrypt -512 bits-
    //

    /**
     * @brief rcrypt512_enc
     *
     * @param key Key.
     * @param str Information to be locked.
     */
    inline void rcrypt512_enc(std::string_view key, std::string *str) {
        for (unsigned short int u = 0; u < 1024; u++) {
            // Vars.
            std::string *EncProcess;

            // Encryption process.
            EncProcess = Red::EncryptResECB512(*str, key);
            *str = *EncProcess;
            delete EncProcess;
        }
    }

    /**
     * @brief rcrypt512_dec
     *
     * @param key Key.
     * @param str Information to be unlocked.
     */
    inline void rcrypt512_dec(std::string_view key, std::string *str) {
        for (unsigned short int u = 0; u < 1024; u++) {
            // Vars.
            std::string *EncProcess;

            // Encryption process.
            EncProcess = Red::DecryptResECB512(*str, key);
            *str = *EncProcess;
            delete EncProcess;
        }
    }

    /**
     * @brief rcrypt512_hash
     *
     * @param key Key.
     * @param str Information to be encrypted and hashed after that.
     *
     * @return Pointer to a new string with hash.
     */
    inline std::string * rcrypt512_hash(std::string_view key, std::string_view str) {
        // Getting encrypted.
        std::string *crypted = new std::string(str);
        rcrypt512_enc(key, crypted);

        // Getting the hashed string.
        std::string *hashed = Red::Sha256Hash(crypted);

        // Finishing.
        return hashed;
    }


    //
    // Rcrypt -1024 bits-
    //

    /**
     * @brief rcrypt1024_enc
     *
     * @param key Key.
     * @param str Information to be locked.
     */
    inline void rcrypt1024_enc(std::string_view key, std::string *str) {
        for (unsigned short int u = 0; u < 1024; u++) {
            // Vars.
            std::string *EncProcess;

            // Encryption process.
            EncProcess = Red::EncryptResECB1024(*str, key);
            *str = *EncProcess;
            delete EncProcess;
        }
    }

    /**
     * @brief rcrypt1024_dec
     *
     * @param key Key.
     * @param str Information to be unlocked.
     */
    inline void rcrypt1024_dec(std::string_view key, std::string *str) {
        for (unsigned short int u = 0; u < 1024; u++) {
            // Vars.
            std::string *EncProcess;

            // Encryption process.
            EncProcess = Red::DecryptResECB1024(*str, key);
            *str = *EncProcess;
            delete EncProcess;
        }
    }

    /**
     * @brief rcrypt1024_hash
     *
     * @param key Key.
     * @param str Information to be encrypted and hashed after that.
     *
     * @return Pointer to a new string with hash.
     */
    inline std::string * rcrypt1024_hash(std::string_view key, std::string_view str) {
        // Getting encrypted.
        std::string *crypted = new std::string(str);
        rcrypt1024_enc(key, crypted);

        // Getting the hashed string.
        std::string *hashed = Red::Sha256Hash(crypted);

        // Finishing.
        return hashed;
    }


    //
    // Rcrypt -1536 bits-
    //

    /**
     * @brief rcrypt1536_enc
     *
     * @param key Key.
     * @param str Information to be locked.
     */
    inline void rcrypt1536_enc(std::string_view key, std::string *str) {
        for (unsigned short int u = 0; u < 1024; u++) {
            // Vars.
            std::string *EncProcess;

            // Encryption process.
            EncProcess = Red::EncryptResECB1536(*str, key);
            *str = *EncProcess;
            delete EncProcess;
        }
    }

    /**
     * @brief rcrypt1536_dec
     *
     * @param key Key.
     * @param str Information to be unlocked.
     */
    inline void rcrypt1536_dec(std::string_view key, std::string *str) {
        for (unsigned short int u = 0; u < 1024; u++) {
            // Vars.
            std::string *EncProcess;

            // Encryption process.
            EncProcess = Red::DecryptResECB1536(*str, key);
            *str = *EncProcess;
            delete EncProcess;
        }
    }

    /**
     * @brief rcrypt1536_hash
     *
     * @param key Key.
     * @param str Information to be encrypted and hashed after that.
     *
     * @return Pointer to a new string with hash.
     */
    inline std::string * rcrypt1536_hash(std::string_view key, std::string_view str) {
        // Getting encrypted.
        std::string *crypted = new std::string(str);
        rcrypt1536_enc(key, crypted);

        // Getting the hashed string.
        std::string *hashed = Red::Sha256Hash(crypted);

        // Finishing.
        return hashed;
    }
}
#endif // RED_RCRYPT_H
