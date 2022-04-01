#include <iostream>
#include <string>

#include "../RedLibrary/RedTypes.h"

int main() {
    //
    // Size-fixed nums.
    //

    Red::int_t a = 4;
    Red::uint32_t b = 18446744073709551615;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Red::uint512_t
    // Red::uint1024_t
    // Red::uint2048_t
    // Red::uint4096_t
    Red::uint8192_t c = -1;
    // Red::uint16384_t
    // Red::uint32768_t
    // Red::uint65536_t
    // Red::uint131072_t
    // Red::uint262144_t
    // Red::uint524288_t
    // Red::uint1048576_t
    // Red::uint2097152_t
    // Red::uint4194304_t
    // Red::uint8388608_t
    // Red::uint16777216_t
    // Red::uint33554432_t
    // Red::uint67108864_t
    // Red::uint134217728_t
    // Red::uint268435456_t
    // Red::uint536870912_t
    // Red::uint1073741824_t
    // Red::uint2147483648_t

    std::cout << std::endl << c << std::endl << std::endl;


    //
    // Endless one.
    //

    Red::number_t *e = new Red::number_t(2);

    *e <<= 1024 - 1; // 2 ** 1024.

    std::cout << "e = " << *e << std::endl;

    delete e;

    return 0;
}
