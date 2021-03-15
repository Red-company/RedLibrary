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
#include <stdlib.h>
#include <ctime>
#include <math.h>

// RedLibrary.
#include "RedTypes.h"

namespace Red {
    class DiffieHellman {
        private:
            //
            // Variables.
            //

            /// x = G**a mod P

            Red::uint32_t G, P, a;

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
            Red::uint32_t  power(Red::uint32_t a, Red::uint32_t b,
                                                  Red::uint32_t P) {
                if (b == 1) {
                    return a;
                } else {
                    return (((Red::uint32_t) pow(a, b)) % P);
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
            DiffieHellman(Red::uint32_t ResultNum = 0,
                          Red::uint32_t ModificatedNum = 0,
                          Red::uint32_t SecretNum = 0)
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
            void Set(Red::uint32_t ResultNum,
                     Red::uint32_t ModificatedNum,
                     Red::uint32_t SecretNum) {
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
            Red::uint32_t GetPublicValue() {
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
            Red::uint32_t GetSymmetricKey(Red::uint32_t x) {
                return power(x, a, P);
            }

            /**
             * @brief GenerateSecret
             *
             * GeneratedKey = G**a mod P
             *
             * Where,
             * @param g G number.
             * @param p P number.
             *
             * @return Generated key.
             */
            static Red::uint32_t GenerateSecret(Red::uint32_t& Srand) {
                srand(time(0));
                return (Red::uint32_t) rand() % Srand + 1;
            }

            // Base dtor.
            ~DiffieHellman() {}
    };
}

#endif // RED_DIFFIEHELLMAN_H
