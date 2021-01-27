#include <iostream>

#include "../RedLibrary/src/RedEncryptionAlgorithms/ResCBC1536.h"
#include "../RedLibrary/src/Hex.h"

int main() {
    std::string key = "0123456789abcdef12345678123456780123456789abcdef12345678123456780123456789abcdef12345678123456780123456789abcdef12345678123456780123456789abcdef12345678123456780123456789abcdef1234567812345678";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string EncryptedStr = Red::EncryptResCBC1536(in, key, iv);
    std::string EncryptedHex = Red::GetHexArray(EncryptedStr);

    std::cout << "Encrypted(hex): '" << EncryptedHex << "'." << std::endl;

    std::string ForDecrypt = Red::GetStrArray(EncryptedHex);
    std::string Decrypted  = Red::DecryptResCBC1536(ForDecrypt, key, iv);

    std::cout << "Decrypted(str): '" << Decrypted << "'." << std::endl;

    return 0;
}