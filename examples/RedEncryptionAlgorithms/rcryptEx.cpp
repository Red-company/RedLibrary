#include <iostream>
#include <vector>
#include <string>

#include "../RedLibrary/RedEncryptionAlgorithms/rcrypt.h" // Rewrite.
#include "../RedLibrary/Hex.h"

int main() {
    system("clear");

    std::string *enc = new std::string("Some text or info here.");


    //
    // 512
    //

    {
        std::string key = "1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef";

        std::string *ex = new std::string(*enc);



        // Encryption.
        Red::rcrypt512_enc(key, ex);

        // Hexing.
        std::string *hx = Red::GetHexArray(*ex);

        // Out.
        std::cout << "Encryption(512):" << std::endl;
        std::cout << "Enc(hex): " << *hx << std::endl;
        std::cout << "\n" << std::endl;



        // Dehexing.
        std::string *sr = Red::GetStrArray(*hx);

        // Decryption.
        Red::rcrypt512_dec(key, sr);

        // Out.
        std::cout << "Decryption(512):" << std::endl;
        std::cout << "Enc(str): " << *sr << std::endl;
        std::cout << "\n" << std::endl;



        // Hash.
        std::string *hs = Red::rcrypt512_hash(key, *ex);

        // Out.
        std::cout << "Hash(512):" << std::endl;
        std::cout << "Hash(str): " << *hs << std::endl;
        std::cout << "\n" << std::endl;

        // Finishing.
        delete ex;
        delete hx;
        delete sr;
        delete hs;
    }

    //
    // 1024
    //

    {
        std::string key = "1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef";

        std::string *ex = new std::string(*enc);



        // Encryption.
        Red::rcrypt1024_enc(key, ex);

        // Hexing.
        std::string *hx = Red::GetHexArray(*ex);

        // Out.
        std::cout << "Encryption(1024):" << std::endl;
        std::cout << "Enc(hex): " << *hx << std::endl;
        std::cout << "\n" << std::endl;



        // Dehexing.
        std::string *sr = Red::GetStrArray(*hx);

        // Decryption.
        Red::rcrypt1024_dec(key, sr);

        // Out.
        std::cout << "Decryption(1024):" << std::endl;
        std::cout << "Enc(str): " << *sr << std::endl;
        std::cout << "\n" << std::endl;



        // Hash.
        std::string *hs = Red::rcrypt1024_hash(key, *ex);

        // Out.
        std::cout << "Hash(1024):" << std::endl;
        std::cout << "Hash(str): " << *hs << std::endl;
        std::cout << "\n" << std::endl;

        // Finishing.
        delete ex;
        delete hx;
        delete sr;
        delete hs;
    }

    //
    // 1536
    //

    {
        std::string key = "1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef";

        std::string *ex = new std::string(*enc);



        // Encryption.
        Red::rcrypt1536_enc(key, ex);

        // Hexing.
        std::string *hx = Red::GetHexArray(*ex);

        // Out.
        std::cout << "Encryption(1536):" << std::endl;
        std::cout << "Enc(hex): " << *hx << std::endl;
        std::cout << "\n" << std::endl;



        // Dehexing.
        std::string *sr = Red::GetStrArray(*hx);

        // Decryption.
        Red::rcrypt1536_dec(key, sr);

        // Out.
        std::cout << "Decryption(1536):" << std::endl;
        std::cout << "Enc(str): " << *sr << std::endl;
        std::cout << "\n" << std::endl;



        // Hash.
        std::string *hs = Red::rcrypt1536_hash(key, *ex);

        // Out.
        std::cout << "Hash(1536):" << std::endl;
        std::cout << "Hash(str): " << *hs << std::endl;
        std::cout << "\n" << std::endl;

        // Finishing.
        delete ex;
        delete hx;
        delete sr;
        delete hs;
    }

    return 0;
}
