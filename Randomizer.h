/**
 * @file    Randomizer.h
 * @brief   Randomizer is a lib which contains a 'Randomize' function.
 *
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_RANDOMIZER_H
#define RED_RANDOMIZER_H

#include <stdlib.h>
#include <time.h>
#include <math.h>

#define REDRANDOMIZER_VERSION "1.2"

#include "RedTypes.h"


namespace Red {
    /**
     * @brief Randomize
     *
     * Used to generate a long random number.
     *
     * @return Long random number.
     */
    inline unsigned long long int * Randomize() {
        srand((unsigned int) time(nullptr));

        unsigned long long *randnumber = new unsigned long long int(0);
        int digits[20];

        for (int i = 19; i >= 1; i--) {
          digits[i] = rand() % 10;
        }

        for (int i = 19; i >= 1; i--) {
           unsigned long long power = pow(10, i - 1);

            if (power % 2 != 0 && power != 1) {
                power++;
            }

            *randnumber += power * digits[i];
        }

        return randnumber;
    }

    /**
     * @brief Randomizer_custom
     *
     * Used to generate a long random number.
     *
     * @param len Len of end num.
     *
     * @return  Long random number.
     */
    inline Red::bignum_t * Randomizer_custom(unsigned long long int *len) {
        srand((unsigned int) time(nullptr));

        Red::bignum_t *randnumber = new Red::bignum_t();
        int *digits = new int[20]();

        for (int i = *len; i >= 1; i--) {
          digits[i] = rand() % 10;
        }

        for (int i = *len; i >= 1; i--) {
           unsigned long long power = pow(10, i - 1);

            if (power % 2 != 0 && power != 1) {
                power++;
            }

            *randnumber += power * digits[i];
        }

        delete[] digits;

        return randnumber;
    }
}

#endif // RED_RANDOMIZER_H
