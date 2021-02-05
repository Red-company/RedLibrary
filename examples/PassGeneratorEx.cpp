#include <iostream>

#include "../RedLibrary/PassGenerator.h"

int main() {
    unsigned short int PassLength = 16;
    std::cout << "Generated pass: '" << Red::GeneratePassword(PassLength) << "'." << std::endl;

    return 0;
}