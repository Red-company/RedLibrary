#include <iostream>
#include <string>

#include "../RedLibrary/src/Hex.h"

int main() {
    system("clear");

    std::string Str = "Hello world!";

    std::string HexStr = Red::Hex::GetHexArray(Str);

    std::cout << "Str(hex): '" << HexStr << "'." << std::endl;

    std::string Back = Red::Hex::GetStrArray(HexStr);

    std::cout << "Str(str): '" << Back << "'." << std::endl;
}
