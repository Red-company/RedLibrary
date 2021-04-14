#include <iostream>

#include "../RedLibrary/PassGenerator.h"

int main() {
    unsigned short int PassLength = 48;

    std::cout << "Generated pass: '" << Red::GeneratePassword(PassLength, RED_PASSGENERATOR_NUMS_AND_LETTERS) << "'." << std::endl;
    std::cout << "Generated pass: '" << Red::GeneratePassword(PassLength, RED_PASSGENERATOR_ONLY_NUMS) << "'." << std::endl;

    return 0;
}
