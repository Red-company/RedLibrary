/**
 * @file    main.cpp
 * @brief   Encryption/decryption application.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include <iostream>
#include <string>

#include "Va1/Va1.h"

int main() {
    std::string inp;

    while (true) {
        system("clear");
        std::cout << "\033[4mChoose operation:\033[0m 1)Encode 2)Decode." << std::endl << std::endl << "[\033[93mVa1\033[0m]  > ";

        std::cin >> inp;

        // Encrypting.
        if (inp == "1") {
            system("clear");
            std::cout << "\033[4mEnter a message.\033[0m" << std::endl << std::endl << "[\033[93mVa1\033[0m] > ";

            std::cin.ignore();
            inp.clear();
            getline(std::cin, inp);
            std::cout << std::endl;

            std::cout << "[\033[93mVa1\033[0m] \033[4mEncrypted message:\033[0m" << std::endl << std::endl << *Red::Va1Encode(&inp);
            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();

        // Decrypting.
        } else if (inp == "2") {
            system("clear");
            std::cout << "\033[4mEnter a message.\033[0m" << std::endl << std::endl << "[\033[93mVa1\033[0m] > ";

            std::cin.ignore();
            inp.clear();
            getline(std::cin, inp);
            std::cout << std::endl;

            std::cout << "[\033[93mVa1\033[0m] Decrypted message:" << std::endl << std::endl << *Red::Va1Decode(&inp);
            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();
        }
    }
}
