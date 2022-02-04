/**
 * @file    PassGenerator.h
 * @brief   PassGenerator has function which generates password of length you need.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_PASSGENERATOR_H
#define RED_PASSGENERATOR_H

#include <string>
#include <ctime>

#define REDPASSGENERATOR_VERSION "1.0"

#define REDPASSGENERATOR_ONLY_NUMS        "only nums"
#define REDPASSGENERATOR_NUMS_AND_LETTERS "nums and letters"

namespace Red {
    /**
     * @brief GeneratePassword
     *
     * @param PassLen Length of password which you want to get
     *
     * @return Generated pass
     */
    std::string GeneratePassword(unsigned short int& PassLen, std::string mode) {
        std::string Result = "";

        srand((unsigned int) time(nullptr));

        if (mode == REDPASSGENERATOR_ONLY_NUMS) {
            std::string alphanum1 = "0123456789";

            for (unsigned short int i = 0; i < PassLen; i++) {
                Result += alphanum1[(unsigned long long int) rand() % alphanum1.length()];
            }

        } else {
            std::string alphanum2 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            for (unsigned short int i = 0; i < PassLen; i++) {
                Result += alphanum2[(unsigned long long int) rand() % alphanum2.length()];
            }
        }

        return Result;
    }
}

#endif // RED_PASSGENERATOR_H
