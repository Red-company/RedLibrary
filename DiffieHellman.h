/**
 * @file    DiffieHellman.h
 * @brief   DiffieHellman is a lib which implements DiffieHellman's key exchange.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_DIFFIEHELLMAN_H
#define RED_DIFFIEHELLMAN_H

// System libs.
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <math.h>

// External libs.
#include <boost/multiprecision/cpp_int.hpp>

// RedLibrary.
#include "RedTypes.h"

#define REDDIFFIEHELLMAN_VERSION "1.2"

namespace Red {
    /// Creating a template for integers, because we need it to be cross-typed.
    template<class INT_SIZE>
    class DiffieHellman {
        private:
            //
            // Variables.
            //

            /// x = G**a mod P

            INT_SIZE G, P, a;

            //
            // Private functions.
            //

            /**
             * @brief power
             *
             * Serves to generate a key using a, b, P.
             *
             * @param a Number which we will modificate.
             * @param b Chosen private key.
             * @param P Result number.
             *
             * @return Generated key.
             */
            inline INT_SIZE power(const INT_SIZE a, const INT_SIZE b, const INT_SIZE P) const {
                if (b == 1) {
                    return a;

                } else {
                    // Unfortunately we have to write a lot here, because there is no a good way to write it shorter.
                    // So, let's do that!

                    /// Need to get cpp_int version of base.
                    boost::multiprecision::cpp_int a_c = boost::multiprecision::cpp_int(a);

                    /// And ui version of our exponent.
                    Red::uint_t b_int = 0;

                    {
                        std::stringstream ss;
                        ss << b;
                        ss >> b_int;
                    }

                    /// Let's get exponented 'a'...
                    boost::multiprecision::cpp_int ab = boost::multiprecision::pow(a_c, b_int);

                    /// Now we need cpp_int version of 'P'.
                    boost::multiprecision::cpp_int p_c = 0;

                    {
                        std::stringstream ss;
                        ss << P;
                        ss >> p_c;
                    }

                    /// Moded expenented 'a' is needed...
                    boost::multiprecision::cpp_int abp = ab % p_c;

                    /// Now we just need to convert it to the type we need.
                    INT_SIZE res = 0;

                    {
                        std::stringstream ss;
                        ss << abp;
                        ss >> res;
                    }

                    /// Yay, we finished this.
                    return res;
                }
            }

        public:
            /**
             * @brief DiffieHellman
             *
             * GeneratedKey = G**a mod P
             *
             * Where,
             * @param ResultNum G number.
             * @param ModificatedNum P number.
             * @param SecretNum Secret number.
             */
            DiffieHellman(INT_SIZE ResultNum = 0,
                          INT_SIZE ModificatedNum = 0,
                          INT_SIZE SecretNum = 0)
                : G(ResultNum), P(ModificatedNum), a(SecretNum) {}

            /**
             * @brief Set
             *
             * GeneratedKey = G**a mod P
             *
             * Where,
             * @param ResultNum G number.
             * @param ModificatedNum P number.
             */
            void Set(INT_SIZE ResultNum,
                     INT_SIZE ModificatedNum,
                     INT_SIZE SecretNum) {
                G = ResultNum;
                P = ModificatedNum;
                a = SecretNum;
            }

            /**
             * @brief GetPublicValue
             *
             * Serves to calculate a key for partner.
             *
             * @return Key for public exchange.
             */
            INT_SIZE GetPublicValue() const {
                return power(G, a, P);
            }

            /**
             * @brief GetSymmetricKey
             *
             * Serves to to calculate symmetric key.
             *
             * @param x Partner's key, which we got after exchange part.
             *
             * @return Shared secret.
             */
            INT_SIZE GetSymmetricKey(INT_SIZE x) const {
                return power(x, a, P);
            }

            // Base dtor.
            ~DiffieHellman() {}
    };
}

#endif // RED_DIFFIEHELLMAN_H
