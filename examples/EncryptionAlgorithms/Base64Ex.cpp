#include <iostream>
#include <string>

#include "Base64.h"

int main() {
    std::string s;

    while (true) {
        system("clear");
        std::cout << "\033[4mChoose operation:\033[0m 1)Encode 2)Decode." << std::endl << std::endl << "[\033[93mBase64\033[0m]  > ";

        getline(std::cin, s);

        // Encrypting.
        if (s == "1") {
            system("clear");
            std::cout << "\033[4mEnter a message.\033[0m" << std::endl << std::endl << "[\033[93mBase64\033[0m] > ";

            getline(std::cin, s);
            std::cout << std::endl;

            std::cout << "[\033[93mBase64\033[0m] \033[4mEncrypted message:\033[0m" << std::endl << std::endl << *Red::Base64Encode(&s);
            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();

        // Decrypting.
        } else if (s == "2") {
            system("clear");
            std::cout << "\033[4mEnter a message.\033[0m" << std::endl << std::endl << "[\033[93mBase64\033[0m] > ";

            getline(std::cin, s);
            std::cout << std::endl;

            std::cout << "[\033[93mBase64\033[0m] Decrypted message:" << std::endl << std::endl << *Red::Base64Decode(&s);
            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();
        }
    }
}
