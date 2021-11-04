#include <iostream>
#include <string>

#include "../RedLibrary/RedTypes.h"

int main() {
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

    std::cout << std::endl << c << std::endl;

    return 0;
}