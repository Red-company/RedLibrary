/**
 * @file    Exceptions.h
 * @ingroup RedConfig
 * @brief   Definitions of RedConfig exceptions.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef REDCONFIG_EXCEPTIONS_H
#define REDCONFIG_EXCEPTIONS_H

#include <exception>

namespace Red {
    namespace RedConfig {
        namespace Exceptions {
            /**
             * @brief can_not_open_file
             *
             * @throw If can't open RedConfig file.
             */
            class can_not_open_file : public std::exception {
                public:
                    virtual const char * what() const throw() {
                        return "can_not_open_file";
                    }
            };

            /**
             * @brief can_not_create_file
             *
             * @throw If can't create RedConfig file.
             */
            class can_not_create_file : public std::exception {
                public:
                    virtual const char * what() const throw() {
                        return "can_not_create_file";
                    }
            };
        }
    }
}

#endif // REDCONFIG_EXCEPTIONS_H
