#include <iostream>
#include <string>

#include "../RedLibrary/RedTypes.h"

int main() {
    Red::int_t a = 4;
    Red::uint32_t b = 18446744073709551615;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}