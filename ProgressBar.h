/**
 * @file    ProgressBar.h
 * @brief   ProgressBar is a lib, that shows a progress bar in terminal.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_PROGRESSBAR_H
#define RED_PROGRESSBAR_H

#include <iostream>
#include <string>

namespace Red {
    class ProgressBar {
        public:
            // Base ctor.
            ProgressBar() {}

            // Increment Percent var.
            inline void Increment() {
                if (Percent <= 100) {
                    Percent++;
                }
            }

            // Show progress bar.
            inline void Show() {
                std::cout << "\r\e[42m";

                Show_main();

                std::cout << std::flush;
            }

            // Show progress bar (Red line).
            inline void Red_Show() {
                std::cout << "\r\e[101m";

                Show_main();

                std::cout << std::flush;
            }

        private:
            /**
             * @brief The [REDPROGRESSBAR_VERSION] C preprocessor macro in the ProgressBar.h
             * header evaluates to a string literal that is the ProgressBar version
             * in the format "X.Y.Z" where X is the major version number
             * and Y is the minor version number and Z is the release number.
             *
             * The [REDPROGRESSBAR_VERSION_NUMBER] C preprocessor macro resolves to an integer
             * with the value (X*100 + Y*10 + Z) where X, Y, and Z are the same
             * numbers used in [REDPROGRESSBAR_VERSION].
             */
            #define REDPROGRESSBAR_VERSION           "1.0.0" // 1.0.0
            #define REDPROGRESSBAR_VERSION_NUMBER     100    // 1.0.0

            // Show progress bar function.
            inline void Show_main() {
                unsigned short int NumOfGreenCubes = Percent / 2;

                for (unsigned short int g = 0; g < NumOfGreenCubes; g++) {
                    std::cout << " ";
                }

                std::cout << "\e[0m\e[47m";

                for (unsigned short int h = 0; h + NumOfGreenCubes < 50; h++) {
                    std::cout << " ";
                }

                std::cout << "\e[0m ";

                std::cout << Percent << "% ";
            }

            // Variables.
            unsigned short int Percent = 0;
    };
}

#endif // RED_PROGRESSBAR_H
