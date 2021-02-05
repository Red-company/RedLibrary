#include <iostream>

#include "../RedLibrary/HashFunctions/Sha256.h"

int main() {
    system("clear");

    std::string Buf = "Simple msg";

    std::cout << "Msg: '" << Buf << "'." << std::endl;
    std::cout << Red::Sha256Hash(Buf) << std::endl;
}