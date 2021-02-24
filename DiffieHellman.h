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

            Red::uint64_t G, P, a;

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
            Red::uint64_t power(Red::uint64_t a, Red::uint64_t b,
                                                 Red::uint64_t P) {
                if (b == 1) {
                    return a;
                } else {
                    return (((Red::uint64_t) pow(a, b)) % P);
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
            DiffieHellman(Red::uint64_t ResultNum = 0,
                          Red::uint64_t ModificatedNum = 0,
                          Red::uint64_t SecretNum = 0)
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
            void Set(Red::uint64_t ResultNum,
                     Red::uint64_t ModificatedNum,
                     Red::uint64_t SecretNum) {
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
            Red::uint64_t GetPublicValue() {
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
            Red::uint64_t GetSymmetricKey(Red::uint64_t x) {
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
            static Red::uint64_t GenerateSecret(Red::uint64_t& Srand) {
                srand(time(0));
                return rand() % Srand + 1;
            }

            // Base dtor.
            ~DiffieHellman() {}
    };
}

#endif // RED_DIFFIEHELLMAN_H
