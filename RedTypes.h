/**
 * @file    RedTypes.h
 * @brief   RedTypes is a lib which serves to compress int and char definitions.
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_REDTYPES_H
#define RED_REDTYPES_H

namespace Red {
    typedef unsigned char           uint8_t;
    typedef unsigned short      int uint16_t;
    typedef unsigned            int uint_t;
    typedef unsigned long       int uint32_t;
    typedef unsigned long  long int uint64_t;
    typedef signed   char           int8_t;
    typedef signed   short      int int16_t;
    typedef signed              int int_t;
    typedef signed   long       int int32_t;
    typedef signed   long  long int int64_t;
}

#endif // RED_REDTYPES_H
