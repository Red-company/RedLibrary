/**
 * @file    Check.h
 * @ingroup RedDataBase
 * @brief   This file contains check functions for RDB.
 *
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_DATABASE_CHECK_H
#define RED_DATABASE_CHECK_H

#include <sys/stat.h>
#include <string>

namespace Red {
    namespace RedDataBase {
        /**
         * @brief DataBaseExists
         *
         * @param path Path to RDB.
         *
         * @return True if RDB exists, false if not.
         */
        inline bool DataBaseExists(std::string& path) {
            struct stat buffer;
            return (stat(path.c_str(), &buffer) == 0);
        }
    }
}


#endif // RED_DATABASE_CHECK_H
