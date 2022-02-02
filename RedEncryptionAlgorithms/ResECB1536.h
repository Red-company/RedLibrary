/**
 * @file    ResECB1536.h
 * @brief   Definition of Res ECB 1536 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_RESECB1536_H
#define RED_RESECB1536_H

#include <string>

namespace Red {
    /**
     * @brief EncryptResECB1536
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    std::string * EncryptResECB1536(const std::string& in, const std::string_view key);

    /**
     * @brief EncryptResECB1536
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    std::string * DecryptResECB1536(const std::string& in, const std::string_view key);
}

#endif // RED_RESECB1536_H
