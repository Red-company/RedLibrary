#include <iostream>
#include <string>

#include "../RedLibrary/Hex.h"

int main() {
    system("clear");

    std::string Str = "Hello world!";

    std::string HexStr = Red::GetHexArray(Str);

    std::cout << "Str(hex): '" << HexStr << "'." << std::endl;

    std::string Back = Red::GetStrArray(HexStr);

    std::cout << "Str(str): '" << Back << "'." << std::endl;
}
