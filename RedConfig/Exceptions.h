/**
 * @file    Exceptions.h
 * @ingroup RedConfig
 * @brief   Definitions of RedConfig exceptions.
 *
 * Copyright (c) 2020-forever Vlad Rogozin (vlad.rogozin@bhcc.edu)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_CONFIG_EXCEPTIONS_H
#define RED_CONFIG_EXCEPTIONS_H

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

#endif // RED_CONFIG_EXCEPTIONS_H
