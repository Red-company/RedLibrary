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
#include <cstdlib>

namespace Red {
    /**
     * @brief GeneratePassword
     *
     * @param PassLen   Length of password which you want to get
     *
     * @return Generated pass
     */
    inline std::string GeneratePassword(unsigned short int& PassLen) {
        const char         alphanum[]    = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        unsigned short int string_length = sizeof (alphanum) - 1;
         std::string       Result        = "";

        srand((unsigned int) time(0));

        for (unsigned short int i = 0; i < PassLen; i++) {
            Result += alphanum[rand() % string_length];
        }

        return Result;
    }
}

#endif // RED_PASSGENERATOR_H
