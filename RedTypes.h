/**
 * @file    RedTypes.h
 * @brief   RedTypes is a lib which serves to compress int and char definitions.
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_TYPES_H
#define RED_TYPES_H

#include <boost/multiprecision/cpp_int.hpp>

#include <iostream>
#include <string>
#include <bit>

#define REDTYPES_VERSION "2.0"


namespace Red {
    //
    // Small nums.
    //

    // Standart size.
    typedef unsigned char           uint8_t;
    typedef unsigned short      int uint16_t;
    typedef unsigned            int uint_t;
    typedef unsigned long  long int uint32_t;
    typedef signed   char           int8_t;
    typedef signed   short      int int16_t;
    typedef signed              int int_t;
    typedef signed   long  long int int32_t;


    //
    // Huge nums.
    //

    // Long size.
    using uint512_t  = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512,  512,  boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint1024_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint2048_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint4096_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint8192_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<8192, 8192, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint16384_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<16384, 16384, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint32768_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<32768, 32768, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint65536_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<65536, 65536, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint131072_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<131072, 131072, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint262144_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<262144, 262144, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint524288_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<524288, 524288, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint1048576_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1048576, 1048576, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint2097152_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2097152, 2097152, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint4194304_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4194304, 4194304, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint8388608_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<8388608, 8388608, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint16777216_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<16777216, 16777216, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint33554432_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<33554432, 33554432, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint67108864_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<67108864, 67108864, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint134217728_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<134217728, 134217728, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint268435456_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<268435456, 268435456, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint536870912_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<536870912, 536870912, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint1073741824_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1073741824, 1073741824, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
    using uint2147483648_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2147483648, 2147483648, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;


    //
    // Others.
    //

    // Endless number(theoretical).
    typedef boost::multiprecision::cpp_int number_t;

    // Endless number v2.

    /// Realization.
    class BigInt {
        private:
            std::string digits;

        public:

            // Constructors.

            /**
             * @brief BigInt
             *
             * @param nr Initial number.
             */
            BigInt(unsigned long long nr = 0) {
                do {
                    digits.push_back(nr % 10);
                    nr /= 10;
                } while (nr);
            }

            /**
             * @brief BigInt
             *
             * @param s String with initial number.
             */
            BigInt(std::string& s) {
                digits = "";
                unsigned int n = s.size();

                for (unsigned int i = n - 1; i >= 0; i--) {
                    if (!isdigit(s[i])) {
                        throw("ERROR");
                    }

                    digits.push_back(s[i] - '0');
                }
            }

            /**
             * @brief BigInt
             *
             * @param s String with initial number.
             */
            BigInt(const char *s) {
                digits = "";

                for (unsigned int i = strlen(s) - 1; i >= 0; i--) {
                    if (!isdigit(s[i])) {
                        throw("ERROR");
                    }

                    digits.push_back(s[i] - '0');
                }
            }

            /**
             * @brief BigInt
             *
             * @param a String with initial number.
             */
            BigInt(BigInt& a) {
                digits = a.digits;
            }


            // Helper Functions.

            /**
             * @brief divide_by_2
             *
             * @param a Number to divide.
             */
            friend void divide_by_2(BigInt& a);

            /**
             * @brief Null
             *
             * @param a Number.
             *
             * @return True/False.
             */
            friend bool Null(const BigInt&);

            /**
             * @brief Length
             *
             * @param a Number.
             *
             * @return Len of number.
             */
            friend int Length(const BigInt&);

            /**
             * @brief BigInt::operator []
             *
             * @param index Index of character.
             *
             * @return Character.
             */
            int operator[](const int) const;


                       /* * * * Operator Overloading * * * */

            // Direct assignment.

            /**
             * @brief BigInt::operator =
             *
             * @param a Num to receive.
             *
             * @return Current num(updated).
             */
            BigInt& operator=(const BigInt&);


            // Post/Pre - Incrementation.

            /**
             * @brief BigInt::operator ++
             *
             * @param temp Service variable.
             *
             * @return Num + 1.
             */
            BigInt& operator++();

            /**
             * @brief BigInt::operator ++
             *
             * @param temp Service variable.
             *
             * @return Num + 1.
             */
            BigInt  operator++(int temp);

            /**
             * @brief BigInt::operator --
             *
             * @param temp Service variable.
             *
             * @return Num - 1.
             */
            BigInt& operator--();

            /**
             * @brief BigInt::operator --
             *
             * @param temp Service variable.
             *
             * @return Num - 1.
             */
            BigInt  operator--(int temp);


            // Addition and Subtraction.

            /**
             * @brief operator +=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Sum a+b.
             */
            friend BigInt& operator+=(BigInt&, const BigInt&);

            /**
             * @brief operator +
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Sum a+b.
             */
            friend BigInt  operator+(const BigInt&, const BigInt&);

            /**
             * @brief operator -
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Subtraction a-b.
             */
            friend BigInt  operator-(const BigInt&, const BigInt&);

            /**
             * @brief operator -=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Subtraction a-b.
             */
            friend BigInt& operator-=(BigInt&, const BigInt&);


            // Comparison operators.

            /**
             * @brief operator ==
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return True/False.
             */
            friend bool operator==(const BigInt&, const BigInt&);

            /**
             * @brief operator !=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return True/False.
             */
            friend bool operator!=(const BigInt&, const BigInt&);

            /**
             * @brief operator >
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return True/False.
             */
            friend bool operator>(const BigInt&, const BigInt&);

            /**
             * @brief operator >=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return True/False.
             */
            friend bool operator>=(const BigInt&, const BigInt&);

            /**
             * @brief operator <
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return True/False.
             */
            friend bool operator<(const BigInt&, const BigInt&);

            /**
             * @brief operator <=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return True/False.
             */
            friend bool operator<=(const BigInt&, const BigInt&);


            // Multiplication and Division.

            /**
             * @brief operator *=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Multiplication ab.
             */
            friend BigInt& operator*=(BigInt&, const BigInt&);

            /**
             * @brief operator *
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Multiplication ab.
             */
            friend BigInt  operator*(const BigInt&, const BigInt&);

            /**
             * @brief operator /=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Result of division.
             */
            friend BigInt& operator/=(BigInt&, const BigInt&);

            /**
             * @brief operator /
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return Result of division.
             */
            friend BigInt  operator/(const BigInt&, const BigInt&);


            // Modulo.

            /**
             * @brief operator %
             *
             * @param a First num.
             * @param b Secind num.
             *
             * @return Remainder.
             */
            friend BigInt  operator%(const BigInt&, const BigInt&);

            /**
             * @brief operator %=
             *
             * @param a First num.
             * @param b Secind num.
             *
             * @return Remainder.
             */
            friend BigInt& operator%=(BigInt&, const BigInt&);


            //Power Function.

            /**
             * @brief operator ^=
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return powered ab.
             */
            friend BigInt& operator^=(BigInt&, const BigInt&);

            /**
             * @brief operator ^
             *
             * @param a First num.
             * @param b Second num.
             *
             * @return powered ab.
             */
            friend BigInt  operator^(BigInt&, const BigInt&);


            // Square Root Function.

            /**
             * @brief sqrt
             *
             * @param a Number to get sqrt of.
             *
             * @return Sqrt from a.
             */
            friend BigInt sqrt(BigInt& a);


            // Read and Write.

            /**
             * @brief operator <<
             *
             * @param in Number to shift.
             * @param a Shift by.
             *
             * @return Output.
             */
            friend std::ostream& operator<<(std::ostream&, const BigInt&);

            /**
             * @brief operator >>
             *
             * @param in Number to shift.
             * @param a Shift by.
             *
             * @return Output.
             */
            friend std::istream& operator>>(std::istream&, BigInt&);


            // Others.

            /**
             * @brief NthCatalan
             *
             * @param n Number to get catalan from position.
             *
             * @return Catalan from position.
             */
            friend BigInt NthCatalan(int n);

            /**
             * @brief NthFibonacci
             *
             * @param n Number to get fibonacci from position.
             *
             * @return Fibonacci from positon.
             */
            friend BigInt NthFibonacci(int n);

            /**
             * @brief Factorial
             *
             * @param n Number to get factorial of.
             *
             * @return Factorial of n.
             */
            friend BigInt Factorial(int n);
        };

        /**
         * @brief Null
         *
         * @param a Number.
         *
         * @return True/False.
         */
        bool Null(const BigInt& a) {
            if (a.digits.size() == 1 && a.digits[0] == 0) {
                return true;
            }

            return false;
        }

        /**
         * @brief Length
         *
         * @param a Number.
         *
         * @return Len of number.
         */
        int Length(const BigInt& a) {
            return a.digits.size();
        }

        /**
         * @brief BigInt::operator []
         *
         * @param index Index of character.
         *
         * @return Character.
         */
        int BigInt::operator[](const int index) const {
            if (digits.size() <= index || index < 0) {
                throw("ERROR");
            }

            return digits[index];
        }

        /**
         * @brief operator ==
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return True/False.
         */
        bool operator==(const BigInt& a, const BigInt& b) {
            return a.digits == b.digits;
        }

        /**
         * @brief operator !=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return True/False.
         */
        bool operator!=(const BigInt& a, const BigInt& b) {
            return !(a == b);
        }

        /**
         * @brief operator <
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return True/False.
         */
        bool operator<(const BigInt& a, const BigInt& b) {
            int n = Length(a), m = Length(b);

            if (n != m) {
                return n < m;
            }

            while (n--) {
                if (a.digits[n] != b.digits[n]) {
                    return a.digits[n] < b.digits[n];
                }
            }

            return false;
        }

        /**
         * @brief operator >
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return True/False.
         */
        bool operator>(const BigInt& a, const BigInt& b) {
            return b < a;
        }

        /**
         * @brief operator >=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return True/False.
         */
        bool operator>=(const BigInt& a, const BigInt& b) {
            return !(a < b);
        }

        /**
         * @brief operator <=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return True/False.
         */
        bool operator<=(const BigInt& a, const BigInt& b) {
            return !(a > b);
        }

        /**
         * @brief BigInt::operator =
         *
         * @param a Num to receive.
         *
         * @return Current num(updated).
         */
        BigInt& BigInt::operator=(const BigInt& a) {
            digits = a.digits;
            return *this;
        }

        /**
         * @brief BigInt::operator ++
         *
         * @param temp Service variable.
         *
         * @return Num + 1.
         */
        BigInt& BigInt::operator++() {
            int i, n = digits.size();

            for (i = 0; i < n && digits[i] == 9; i++) {
                digits[i] = 0;
            }

            if (i == n) {
                digits.push_back(1);
            } else {
                digits[i]++;
            }

            return *this;
        }

        /**
         * @brief BigInt::operator ++
         *
         * @param temp Service variable.
         *
         * @return Num + 1.
         */
        BigInt BigInt::operator++(int temp) {
            BigInt aux;

            aux = *this;
            ++(*this);

            return aux;
        }

        /**
         * @brief BigInt::operator --
         *
         * @param temp Service variable.
         *
         * @return Num - 1.
         */
        BigInt& BigInt::operator--() {
            if (digits[0] == 0 && digits.size() == 1) {
                throw("UNDERFLOW");
            }

            int i, n = digits.size();

            for (i = 0; digits[i] == 0 && i < n; i++) {
                digits[i] = 9;
            }

            digits[i]--;

            if (n > 1 && digits[n - 1] == 0) {
                digits.pop_back();
            }

            return *this;
        }

        /**
         * @brief BigInt::operator --
         *
         * @param temp Service variable.
         *
         * @return Num - 1.
         */
        BigInt BigInt::operator--(int temp) {
            BigInt aux;

            aux = *this;
            --(*this);

            return aux;
        }

        /**
         * @brief operator +=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Sum a+b.
         */
        BigInt& operator+=(BigInt& a, const BigInt& b) {
            int t = 0, s, i;
            int n = Length(a), m = Length(b);

            if (m > n) {
                a.digits.append(m - n, 0);
            }

            n = Length(a);

            for (i = 0; i < n; i++) {
                if (i < m) {
                    s = (a.digits[i] + b.digits[i]) + t;

                } else {
                    s = a.digits[i] + t;
                }

                t = s / 10;
                a.digits[i] = (s % 10);
            }

            if (t) {
                a.digits.push_back(t);
            }

            return a;
        }

        /**
         * @brief operator +
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Sum a+b.
         */
        BigInt operator+(const BigInt& a, const BigInt& b) {
            BigInt temp;

            temp = a;
            temp += b;

            return temp;
        }

        /**
         * @brief operator -=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Subtraction a-b.
         */
        BigInt& operator-=(BigInt& a, const BigInt& b) {
            if (a < b) {
                throw("UNDERFLOW");
            }

            int n = Length(a), m = Length(b);
            int i, t = 0, s;

            for (i = 0; i < n; i++) {
                if (i < m) {
                    s = a.digits[i] - b.digits[i]+ t;

                } else {
                    s = a.digits[i]+ t;
                }


                if (s < 0) {
                    s += 10,
                    t = -1;

                } else {
                    t = 0;
                }

                a.digits[i] = s;
            }

            while (n > 1 && a.digits[n - 1] == 0) {
                a.digits.pop_back(),
                n--;
            }

            return a;
        }

        /**
         * @brief operator -
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Subtraction a-b.
         */
        BigInt operator-(const BigInt& a, const BigInt& b) {
            BigInt temp;

            temp = a;
            temp -= b;

            return temp;
        }

        /**
         * @brief operator *=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Multiplication ab.
         */
        BigInt& operator*=(BigInt& a, const BigInt& b) {
            if (Null(a) || Null(b)) {
                a = BigInt();
                return a;
            }

            int n = a.digits.size(), m = b.digits.size();
            std::vector<int> v(n + m, 0);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    v[i + j] += (a.digits[i] ) * (b.digits[j]);
                }
            }

            n += m;
            a.digits.resize(v.size());

            for (int s, i = 0, t = 0; i < n; i++) {
                s = t + v[i];
                v[i] = s % 10;
                t = s / 10;
                a.digits[i] = v[i];
            }

            for (int i = n - 1; i >= 1 && !v[i]; i--) {
                    a.digits.pop_back();
            }

            return a;
        }

        /**
         * @brief operator *
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Multiplication ab.
         */
        BigInt operator*(const BigInt& a, const BigInt& b){
            BigInt temp;

            temp = a;
            temp *= b;

            return temp;
        }

        /**
         * @brief operator /=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Result of division.
         */
        BigInt& operator/=(BigInt& a, const BigInt& b) {
            if (Null(b)) {
                throw("Arithmetic Error: Division By 0");
            }

            if (a < b) {
                a = BigInt();
                return a;
            }

            if (a == b) {
                a = BigInt(1);
                return a;
            }

            int i, lgcat = 0, cc;
            int n = Length(a), m = Length(b);
            std::vector<int> cat(n, 0);
            BigInt t;

            for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
                t *= 10;
                t += a.digits[i] ;
            }

            for (; i >= 0; i--) {
                t = t * 10 + a.digits[i];

                for (cc = 9; cc * b > t; cc--);

                t -= cc * b;
                cat[lgcat++] = cc;
            }

            a.digits.resize(cat.size());

            for (i = 0; i < lgcat; i++) {
                a.digits[i] = cat[lgcat - i - 1];
            }

            a.digits.resize(lgcat);

            return a;
        }

        /**
         * @brief operator /
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return Result of division.
         */
        BigInt operator/(const BigInt& a, const BigInt& b) {
            BigInt temp;

            temp = a;
            temp /= b;

            return temp;
        }

        /**
         * @brief operator %=
         *
         * @param a First num.
         * @param b Secind num.
         *
         * @return Remainder.
         */
        BigInt& operator%=(BigInt& a, const BigInt& b) {
            if (Null(b)) {
                throw("Arithmetic Error: Division By 0");
            }

            if (a < b) {
                a = BigInt();
                return a;
            }

            if (a == b) {
                a = BigInt(1);
                return a;
            }

            int i, lgcat = 0, cc;
            int n = Length(a), m = Length(b);
            std::vector<int> cat(n, 0);
            BigInt t;

            for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
                t *= 10;
                t += a.digits[i];
            }

            for (; i >= 0; i--) {
                t = t * 10 + a.digits[i];

                for (cc = 9; cc * b > t; cc--);

                t -= cc * b;
                cat[lgcat++] = cc;
            }

            a = t;

            return a;
        }

        /**
         * @brief operator %
         *
         * @param a First num.
         * @param b Secind num.
         *
         * @return Remainder.
         */
        BigInt operator%(const BigInt& a, BigInt& b) {
            BigInt temp;

            temp = a;
            temp %= b;

            return temp;
        }

        /**
         * @brief operator ^=
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return powered ab.
         */
        BigInt& operator^=(BigInt& a, const BigInt& b) {
            BigInt Exponent, Base(a);
            Exponent = b;
            a = 1;

            while (!Null(Exponent)) {
                if (Exponent[0] & 1) {
                    a *= Base;
                }

                Base *= Base;
                divide_by_2(Exponent);
            }

            return a;
        }

        /**
         * @brief operator ^
         *
         * @param a First num.
         * @param b Second num.
         *
         * @return powered ab.
         */
        BigInt operator^(BigInt& a, BigInt& b) {
            BigInt temp(a);
            temp ^= b;
            return temp;
        }

        /**
         * @brief divide_by_2
         *
         * @param a Number to divide.
         */
        void divide_by_2(BigInt& a) {
            int add = 0;

            for (int i = a.digits.size() - 1; i >= 0; i--){
                int digit = (a.digits[i] >> 1) + add;
                add = ((a.digits[i] & 1) * 5);
                a.digits[i] = digit;
            }

            while (a.digits.size() > 1 && !a.digits.back()) {
                a.digits.pop_back();
            }
        }

        /**
         * @brief sqrt
         *
         * @param a Number to get sqrt of.
         *
         * @return Sqrt from a.
         */
        BigInt sqrt(BigInt& a) {
            BigInt left(1), right(a), v(1), mid, prod;
            divide_by_2(right);

            while (left <= right) {
                mid += left;
                mid += right;
                divide_by_2(mid);
                prod = (mid * mid);

                if (prod <= a) {
                    v = mid;
                    ++mid;
                    left = mid;

                } else {
                    --mid;
                    right = mid;
                }

                mid = BigInt();
            }

            return v;
        }

        /**
         * @brief NthCatalan
         *
         * @param n Number to get catalan from position.
         *
         * @return Catalan from position.
         */
        BigInt NthCatalan(int n) {
            BigInt a(1), b;

            for (int i = 2; i <= n; i++) {
                a *= i;
            }

            b = a;

            for (int i = n + 1; i <= 2 * n; i++) {
                b *= i;
            }

            a *= a;
            a *= (n + 1);
            b /= a;

            return b;
        }

        /**
         * @brief NthFibonacci
         *
         * @param n Number to get fibonacci from position.
         *
         * @return Fibonacci from positon.
         */
        BigInt NthFibonacci(int n) {
            BigInt a(1), b(1), c;

            if (!n) {
                return c;
            }

            n--;

            while (n--) {
                c = a + b;
                b = a;
                a = c;
            }

            return b;
        }

        /**
         * @brief Factorial
         *
         * @param n Number to get factorial of.
         *
         * @return Factorial of n.
         */
        BigInt Factorial(int n) {
            BigInt f(1);

            for (int i = 2; i <= n; i++) {
                f *= i;
            }

            return f;
        }

        /**
         * @brief operator >>
         *
         * @param in Number to shift.
         * @param a Shift by.
         *
         * @return Output.
         */
        std::istream& operator>>(std::istream& in, BigInt& a) {
            std::string s;

            in >> s;

            int n = s.size();

            for (int i = n - 1; i >= 0; i--) {
                if (!isdigit(s[i])) {
                    throw("INVALID NUMBER");
                }

                a.digits[n - i - 1] = s[i];
            }

            return in;
        }

        /**
         * @brief operator <<
         *
         * @param in Number to shift.
         * @param a Shift by.
         *
         * @return Output.
         */
        std::ostream& operator<<(std::ostream& out, const BigInt& a) {
            for (int i = a.digits.size() - 1; i >= 0; i--) {
                out << (short) a.digits[i];
            }

            return out;
        }

        /// Definition.
        typedef Red::BigInt bignum_t;


        //
        // Functions.
        //

        /**
         * @brief power_2
         *
         * Works well with small nums, not for long-num usage.
         *
         * @param y 2 ** y
         *
         * @return Pointer to a new cpp_int with result.
         */
        template<class T>
        boost::multiprecision::cpp_int * power_2(T& y) {
            boost::multiprecision::cpp_int *res = new boost::multiprecision::cpp_int(y);

            if (*res == 0) {
                return res;

            } else {
                *res = 2;

                *res <<= y - 1;

                return res;
            }
        }
}

#endif // RED_TYPES_H
