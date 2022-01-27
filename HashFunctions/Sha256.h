/**
 * @file    Sha256.h
 * @brief   Sha256 is hash function implementation.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_SHA256_H
#define RED_SHA256_H

// Version.
#define REDSHA256_VERSION "1.1" // There was no v1.0 macros.

#include <string>

namespace Red {
    /**
     * @brief  Sha256Hash
     *
     * @param  input   string which we will get hash from
     *
     * @return string with hash
     */
    std::string * Sha256Hash(std::string *input);
}

#endif // RED_SHA256_H
