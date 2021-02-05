#include <iostream>

#include "../RedLib/RedEncryptionAlgorithms/ResCBC512.h"
#include "../RedLib/Hex.h"

int main() {
    std::string key = "0123456789abcdef12345678123456780123456789abcdef1234567812345678";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string EncryptedStr = Red::EncryptResCBC512(in, key, iv);
    std::string EncryptedHex = Red::GetHexArray(EncryptedStr);

    std::cout << "Encrypted(hex): '" << EncryptedHex << "'." << std::endl;

    std::string ForDecrypt = Red::GetStrArray(EncryptedHex);
    std::string Decrypted  = Red::DecryptResCBC512(ForDecrypt, key, iv);

    std::cout << "Decrypted(str): '" << Decrypted << "'." << std::endl;

    return 0;
}
