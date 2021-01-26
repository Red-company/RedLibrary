/**
 * @file    ResECB512.h
 * @brief   Definition of Res ECB 512 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_RESECB512_H
#define RED_RESECB512_H

#include <string>

namespace Red {
    /**
     * @brief EncryptResECB512
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    const std::string EncryptResECB512(const std::string& in, const std::string_view key);

    /**
     * @brief EncryptResECB512
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    const std::string DecryptResECB512(const std::string& in, const std::string_view key);
}

#endif // RED_RESECB512_H
