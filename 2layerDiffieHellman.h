/**
 * @file    2layerDiffieHellman.h
 * @brief   2layerDiffieHellman is a lib which implements advanced DiffieHellman's key exchange algorithm.
 *
 * Copyright (c) 2020-forever Vlad Rogozin (vlad.rogozin@bhcc.edu)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_2LAYERDIFFIEHELLMAN_H
#define RED_2LAYERDIFFIEHELLMAN_H

// System libs.
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <string>
#include <random>

// External libs.
#include <boost/multiprecision/cpp_int.hpp>

// RedLibrary.
#include "RedTypes.h"

// Version.
#define RED2LAYERDIFFIEHELLMAN_VERSION "4.0"

// Rand() setups.
#define RED_2lDH_RANDOM_A1_KEY_70  70
#define RED_2lDH_RANDOM_A1_KEY_100 100
#define RED_2lDH_RANDOM_A1_KEY_140 140

// Other.
static Red::bignum_t *RED_2lDH_P_UNLIMITED = new Red::bignum_t(1);

#include <iostream>
namespace Red {
    /// Creating a template for integers, because we need it to be cross-typed.
    class TwoLayerDiffieHellman {
        private:
            //
            // Variables.
            //

            /// x = g**a mod P

            /// Local vars.
            const Red::bignum_t m_G   = 2,   // Base  for part 1.
                                m_Pp = 998; // P num for part 1.

            Red::bignum_t *m_base; // Base for part 2.

            /// User's vars.
            Red::bignum_t *m_P,  // Prime  num.
                          *m_a1, // Secret num for part 1.
                          *m_a2; // Secret num for part 2.


            //
            // Private functions.
            //

            /**
             * @brief power
             *
             * Serves to generate a key using a, b.
             * Uses only in part 1.
             *
             * @param a Number which we will modificate.
             * @param b Chosen private key.
             * @param P Result number.
             *
             * @return Generated key.
             */
            inline Red::bignum_t * power(const Red::bignum_t *a, const Red::bignum_t *b, const Red::bignum_t *P) const {
                Red::bignum_t *res = new Red::bignum_t;

                *res = *a;

                if (*b != 1) {
                    *res ^= *b;
                }

                if (*P != *RED_2lDH_P_UNLIMITED && *res >= *P) {
                    *res %= *P;
                }
                return res;
            }


        public:
            /**
             * @brief TwoLayerDiffieHellman
             *
             * GeneratedKey = G**a mod P
             *
             * Where,
             * @param ModificatedNum P number.
             * @param SecretNum1 Secret number 1.
             * @param SecretNum2 Secret number 2.
             * @param Mode Mode of secret key usage.
             */
            TwoLayerDiffieHellman(Red::bignum_t *ModificatedNum,
                                  Red::bignum_t *SecretNum1,
                                  Red::bignum_t *SecretNum2)
                : m_P(ModificatedNum), m_a1(SecretNum1), m_a2(SecretNum2) {}

            /**
             * @brief Set
             *
             * GeneratedKey = G**a mod P
             *
             * Where,
             * @param ModificatedNum P number.
             * @param SecretNum1 Secret number 1.
             * @param SecretNum2 Secret number 2.
             * @param Mode Mode of secret key usage.
             */
            void Set(Red::bignum_t *ModificatedNum,
                     Red::bignum_t *SecretNum1,
                     Red::bignum_t *SecretNum2) {

                this->m_P  = ModificatedNum;
                this->m_a1 = SecretNum1;
                this->m_a2 = SecretNum2;
            }

            /**
             * @brief Part1_GetPublicValue
             *
             * Serves to calculate a value for partner.
             *
             * @return Value for public exchange.
             */
            Red::bignum_t * Part1_GetPublicValue() const {
                Red::bignum_t *pv;

                /// Getting the first num in protocol.
                pv = power(&this->m_G, this->m_a1, &this->m_Pp);

                return pv;
            }

            /**
             * @brief Part1_GetSymmetricBaseNum
             *
             * Serves to to calculate symmetric value.
             *
             * @param x Partner's key, which we got after exchange part.
             */
            void Part1_GetSymmetricBaseNum(Red::bignum_t *x) {
                m_base   = power(x, this->m_a1, &this->m_Pp);
                std::cout << "base_init: " << *m_base << std::endl;
                *m_base += 2; // base E [2;1000].
                std::cout << "base_prep: " << *m_base << std::endl;
                if (*m_base % *REDSASP_BIGNUM_10 == *REDSASP_BIGNUM_0) {
                    (*m_base)++;
                }
                std::cout << "base_endl: " << *m_base << std::endl;
            }

            /**
             * @brief Part2_GetPublicValue
             *
             * Serves to calculate a value for partner.
             *
             * @return Value for public exchange.
             */
            Red::bignum_t * Part2_GetPublicValue() const {
                std::cout << "p2 base: " << *m_base << std::endl;
                std::cout << "p2 a2: " << *m_a2 << std::endl;
                return power(this->m_base, this->m_a2, this->m_P);
            }

            /**
             * @brief Part2_GetSymmetricSecret
             *
             * Serves to to calculate the final value.
             *
             * @param x Partner's key, which we got after exchange operation.
             *
             * @return Final num.
             */
            Red::bignum_t * Part2_GetSymmetricSecret(Red::bignum_t *x) const {
                return power(x, this->m_a2, this->m_P);
            }

            // Base dtor.
            ~TwoLayerDiffieHellman() {
                delete m_base;
            }
    };
}

#endif // RED_2LAYERDIFFIEHELLMAN_H
