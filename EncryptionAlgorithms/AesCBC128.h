/**
 * @file    AesCBC128.h
 * @brief   Definition of Aes CBC 128 bits algorithm.
 *
 * Copyright (c) 2020-forever Vlad Rogozin (vlad.rogozin@bhcc.edu)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_AESCBC128_H
#define RED_AESCBC128_H

#include <string>

namespace Red {
    /**
     * @brief EncryptAesCBC128
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    std::string * EncryptAesCBC128(
                              const std::string& in,
                              const std::string_view key,
                              const std::string_view iv
                             );

    /**
     * @brief DecryptAesCBC128
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    std::string * DecryptAesCBC128(
                              const std::string& in,
                              const std::string_view key,
                              const std::string_view iv
                             );
}

#endif // RED_AESCBC128_H
