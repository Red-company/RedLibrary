/**
 * @file    RedLog.h
 * @brief   RedLog is a lib which serves to make notes of running your programs.
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_LOG_H
#define RED_LOG_H

#include <string>
#include <fstream>

#define REDLOG_VERSION           "1.0"
#define REDLOG_VERSION_NUMBER     10

#define REDLOG_NO_GROUP "null"

namespace Red {
    class RedLog {
        private:
            // Connection to log file.
            std::ofstream LogFile;

        public:
            /**
             * @brief RedLog
             *
             * Base ctor.
             */
            RedLog();

            /**
             * @brief RedLog
             *
             * Ctor.
             *
             * @param path Path to log file.
             */
            RedLog(std::string& path);

            /**
             * @brief OpenFile
             *
             * Uses to open log file.
             *
             * @param path Path to log file.
             */
            void OpenFile(std::string path);

            /**
             * @brief FileExists
             *
             * Uses to check log file for existance.
             *
             * @param path Path to log file.
             *
             * @return True if log file exists, false if not.
             */
            static bool FileExists(std::string& path) {
                std::ifstream is(path);

                return is.is_open() ? true : false;
            }

            /**
             * @brief CreateLogFile
             *
             * Uses to create log file.
             *
             * @param path Path to log file.
             *
             * @return True if file was created, false if not.
             */
            static bool CreateLogFile(std::string& path) {
                // Creating log file.

                std::ofstream of(path);

                if (!of.is_open()){
                    return false;
                }

                of << "### RedLog version: " << REDLOG_VERSION << " ###";

                of.close();

                // Checking file for existance.

                std::ifstream is(path);

                if (is.is_open()) {
                    return true;

                } else {
                    return false;
                }
            }

            /**
             * @brief DeleteFile
             *
             * Uses to delete log file.
             *
             * @param path Path to log file.
             *
             * @return True if file was deleted successfully, false if not.
             */
            static bool DeleteFile(std::string& path) {
                return std::remove(path.c_str()) == 0 ? true : false;
            }

            /**
             * @brief NewNote
             *
             * Uses to add new line to log file.
             *
             * Date and time will be added automatically.
             *
             * @param group Group of module you logging.
             * @param note String which will be added to log file.
             */
            void NewNote(std::string group, std::string note);

            // Base dtor.
            ~RedLog() {}
    };
}


#endif // RED_LOG_H
