#include <iostream>
#include <string>

#include "../RedLib/EncryptionAlgorithms/AesECB128.h"
#include "../RedLib/Hex.h"

int main() {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef";

    std::string EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string EncryptedHex = Red::GetHexArray(EncryptedStr);

    std::cout << "Encrypted(hex): '" << EncryptedHex << "'." << std::endl;

    std::string ForDecrypt = Red::GetStrArray(EncryptedHex);
    std::string Decrypted  = Red::DecryptAesECB128(ForDecrypt, key);

    std::cout << "Decrypted(str): '" << Decrypted << "'." << std::endl;

    return 0;
}