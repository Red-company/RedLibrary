#include <iostream>
#include <string>

#include "../RedLibrary/src/RedEncryptionAlgorithms/Va1.h"

int main() {
    std::string Str = "Hello world!";

    std::string Enc = Red::Va1Encode(Str);
    std::string Dec = Red::Va1Decode(Enc);

    std::cout << "Va1: '" << Enc << "'." << std::endl;
    std::cout << "Str: '" << Dec << "'." << std::endl;
}