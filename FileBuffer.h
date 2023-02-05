/**
 * @file    FileBuffer.h
 * @brief   Filebuffer is object which uses to save long strings to file.
 *
 * Copyright (c) 2020-forever Vlad Rogozin (vlad.rogozin@bhcc.edu)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_FILEBUFFER_H
#define RED_FILEBUFFER_H

#include <iostream>
#include <fstream>
#include <string>

#define REDFILEBUFFER_VERSION "1.0"

namespace Red {
    class FileBuffer {
        private:
            //
            // Variables.
            //

            std::string            RedBufferAddress;
            unsigned long long int NumOfString = 1;


            //
            // Private funcs.
            //

            /**
             * @brief CheckBufForExistence
             *
             * @return True if file buffer exists.
             */
            inline bool CheckBufForExistence() {
                std::ifstream Check4Buf(RedBufferAddress);
                return Check4Buf.is_open() ? true : false;
            }

            /**
             * @brief AddToFile
             *
             * @param ToAdd String to be added to file buffer.
             */
            inline void AddToFile(const std::string_view ToAdd) {
                std::ofstream AddNewChar(RedBufferAddress, std::ios::app);

                if (AddNewChar.is_open()) {
                    AddNewChar << ToAdd;
                }

                AddNewChar.close();
            }

        public:
            // Ctor.
            FileBuffer() {}

            //
            // Work funcs.
            //

            /**
             * @brief SetupBuffer
             *
             * @param FileAddress Path of FileBuffer.
             *
             * @return True if created, false if not.
             */
            inline bool SetupBuffer(const std::string_view FileAddress) {
                RedBufferAddress = FileAddress;
                std::ofstream CreateNewBuf(RedBufferAddress);
                return CreateNewBuf.is_open() ? true : false;
            }

            /**
             * @brief AddToBuf
             *
             * @param ToBuf Information to be added to FileBuffer.
             *
             * @return True if added successufully, false if not.
             */
            inline bool AddToBuf(const std::string_view ToBuf) {
                size_t            AlreadyWrote = 0;

                if (CheckBufForExistence() == true) {
                    while (AlreadyWrote <= ToBuf.length()) {
                        std::string strbuf(1, ToBuf[AlreadyWrote]);
                        AddToFile(strbuf);

                        AlreadyWrote++;
                    }

                }

                return true;
            }

            /**
             * @brief GetStringTo
             *
             * @param StringReturn String where be loaded information from Filebuffer.
             *
             * @return True if loaded successfully.
             */
            inline bool GetStringTo(std::string *StringReturn) {
                bool GotNextStr = false;

                std::ifstream TakeStr(RedBufferAddress);

                if (TakeStr.is_open()) {
                    std::string StrBuf = "";

                    for (unsigned long long int y = 1; y < NumOfString + 1; y++) {
                        if (getline(TakeStr, StrBuf)) {
                            if (y == NumOfString) {
                                *StringReturn = StrBuf;
                                GotNextStr   = true;
                            }
                        } else {
                            break;
                        }
                    }

                    // Updating Number of string.
                    NumOfString++;
                }

                return GotNextStr;
            }

            // Dtor.
            ~FileBuffer() {
                if (std::remove(RedBufferAddress.c_str()) != 0) {
                    std::cout << "RedBuffer_err: Can't delete buffer ('" << RedBufferAddress << "')." << std::endl;
                }
            }
    };
}

#endif // RED_FILEBUFFER_H
