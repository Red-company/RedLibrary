/**
 * @file    RedTypes.h
 * @brief   RedTypes is a lib which serves to compress int and char definitions.
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_TYPES_H
#define RED_TYPES_H

#include <boost/multiprecision/cpp_int.hpp>

#define REDTYPES_VERSION "1.3"

namespace Red {
    //
    // Small nums.
    //

    // Standart size.
    typedef unsigned char           uint8_t;
    typedef unsigned short      int uint16_t;
    typedef unsigned            int uint_t;
    typedef unsigned long  long int uint32_t;
    typedef signed   char           int8_t;
    typedef signed   short      int int16_t;
    typedef signed              int int_t;
    typedef signed   long  long int int32_t;


    //
    // Huge nums.
    //

    // Long size.
    using uint512_t  = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512,  512,  boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint1024_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint2048_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint4096_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint8192_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<8192, 8192, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint16384_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<16384, 16384, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint32768_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<32768, 32768, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint65536_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<65536, 65536, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint131072_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<131072, 131072, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint262144_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<262144, 262144, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint524288_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<524288, 524288, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint1048576_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1048576, 1048576, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint2097152_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2097152, 2097152, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint4194304_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4194304, 4194304, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint8388608_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<8388608, 8388608, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint16777216_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<16777216, 16777216, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint33554432_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<33554432, 33554432, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint67108864_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<67108864, 67108864, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint134217728_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<134217728, 134217728, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint268435456_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<268435456, 268435456, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint536870912_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<536870912, 536870912, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint1073741824_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1073741824, 1073741824, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint2147483648_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2147483648, 2147483648, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
}

#endif // RED_TYPES_H
