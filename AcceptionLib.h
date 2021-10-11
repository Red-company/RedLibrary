/**
 * @file    AcceptionLib.h
 * @brief   AcceptionLib is a lib which makes terminal questions('[y/n]') easier to do.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_ACCEPTIONLIB_H
#define RED_ACCEPTIONLIB_H

#define REDACCEPTIONLIB_VERSION            "1.0"

// System libs.
#include <iostream>
#include <string>

namespace Red {
    class AcceptionObj {
        public:
            /**
             * @brief AcceptionObj
             *
             * Base ctor.
             */
            AcceptionObj() {}

            /**
             * @brief Request
             *
             * @param Text Text to be shown.
             *
             * @return True if received yes, false if received no.
             */
            bool Request(std::string Text = "Are you sure?") {
                std::string inp = "";

                std::cout << Text << " [y/n]: ";

                while (true) {
                    std::cin >> inp;

                    if (inp[0] == 'y' || inp[0] == 'Y') {
                        return true;

                    } else if (inp[0] == 'n' || inp[0] == 'N') {
                        return false;
                    }
                }
            }
    };
}

#endif // RED_ACCEPTIONLIB_H
