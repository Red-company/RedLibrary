/**
 * @file    ResCBC1024.h
 * @brief   Definition of Res CBC 1024 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_RESCBC1024_H
#define RED_RESCBC1024_H

#include <string>

namespace Red {
    /**
     * @brief EncryptResCBC1024
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    const std::string EncryptResCBC1024(
                              const std::string& in,
                              const std::string_view key,
                              const std::string_view iv
                             );

    /**
     * @brief EncryptResCBC1024
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    const std::string DecryptResCBC1024(
                              const std::string& in,
                              const std::string_view key,
                              const std::string_view iv
                             );
}

#endif // RED_RESCBC1024_H
