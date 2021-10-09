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

#define REDPROGRESSBAR_VERSION            "1.0"
#define REDPROGRESSBAR_VERSION_NUMBER     10

namespace Red {
    class ProgressBar {
        public:
            /**
             * @brief ProgressBar
             *
             * Base ctor.
             */
            ProgressBar() {}

            /**
             * @brief Increment
             *
             * Uses to increment percent variable.
             */
            inline void Increment() {
                if (Percent <= 100) {
                    Percent++;
                }
            }

            /**
             * @brief Show
             *
             * Uses to show progress bar
             */
            inline void Show() {
                std::cout << "\r\e[42m";

                Show_main();

                std::cout << std::flush;
            }

            /**
             * @brief Red_Show
             *
             * Uses to show red progress bar.
             */
            inline void Red_Show() {
                std::cout << "\r\e[101m";

                Show_main();

                std::cout << std::flush;
            }

            // Base ctor.
            ~ProgressBar() {}

        private:

            /**
             * @brief Show_main
             *
             * This function uses to print a progress bar.
             */
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
