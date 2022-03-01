#include <iostream>
#include <string>

#include "Sha256/Sha256.h"

int main() {
    std::string inp;

    while (true) {
        system("clear");
        std::cout << "\033[4mEnter a message.\033[0m" << std::endl << std::endl << "[\033[93mSha256\033[0m] > ";

        std::cin.ignore();
        inp.clear();
        getline(std::cin, inp);
        std::cout << std::endl;
        
        std::string *r = new std::string(*Red::Sha256Hash(&inp));

        std::cout << "[\033[93mSha256\033[0m] \033[4mEncrypted message:\033[0m" << std::endl << std::endl << *r; // Memory leak, it returns
        std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";
        
        delete r;

        std::cin.get();
    }
}
