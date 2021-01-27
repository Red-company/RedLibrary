#include <iostream>
#include <string>

#include "../RedLibrary/src/EncryptionAlgorithms/EncryptAesECB192.h"
#include "../RedLibrary/src/Hex.h"

int main() {
    std::string key = "0123456789abcdef12345678";
    std::string in  = "0123456789abcdef";

    std::string EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string EncryptedHex = Red::GetHexArray(EncryptedStr);

    std::cout << "Encrypted(hex): '" << EncryptedHex << "'." << std::endl;

    std::string ForDecrypt = Red::GetStrArray(EncryptedHex);
    std::string Decrypted  = Red::DecryptAesECB192(ForDecrypt, key);

    std::cout << "Decrypted(str): '" << Decrypted << "'." << std::endl;

    return 0;
}
