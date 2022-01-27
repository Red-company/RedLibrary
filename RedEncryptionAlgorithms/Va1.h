/**
 * @file    Va1.h
 * @brief   Va1 is encryption/decryption lib.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_VA1_H
#define RED_VA1_H

#include <string>

// Version.
#define REDVA1_VERSION "1.1" // There was no v1.0.

namespace Red {
    /**
     * @brief Va1Encode
     *
     * @param ToEnc String to be encoded.
     *
     * @return Encoded string.
     */
    std::string * Va1Encode(const std::string *ToEnc);

    /**
     * @brief Va1Decode
     *
     * @param ToDec String to be decoded.
     *
     * @return Decoded string.
     */
    std::string * Va1Decode(const std::string *ToDec);
}

#endif // RED_VA1_H
