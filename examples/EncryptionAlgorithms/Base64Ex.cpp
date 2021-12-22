#include <iostream>
#include <string>

#include "../RedLibrary/EncryptionAlgorithms/Base64.h"

int main() {
    std::string Str = "Hello world!";

    std::string Enc = Red::Base64Encode(Str);
    std::string Dec = Red::Base64Decode(Enc);

    std::cout << "Base64: '" << Enc << "'." << std::endl;
    std::cout << "Str: '" << Dec << "'." << std::endl;
}
