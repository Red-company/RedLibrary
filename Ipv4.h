/**
 * @file    Ipv4.h
 * @brief   Ipv4 is a lib, which has object with Ipv4 address and functions to interact with it.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_IPV4_H
#define RED_IPV4_H

#include <boost/lexical_cast.hpp>
#include <string>

#define REDIPV4_VERSION           "1.0"
#define REDIPV4_VERSION_NUMBER     10

#define REDIPV4_ALL    "all"
#define REDIPV4_PUBLIC "public"
#define REDIPV4_192    "192"
#define REDIPV4_172    "172"
#define REDIPV4_169    "169"
#define REDIPV4_127    "127"
#define REDIPV4_10     "10"

namespace Red {
    class Ipv4 {
        public:
            //
            // Ctors.
            //

            /// Base ctor.
            Ipv4() {}

            /**
             * @brief Ipv4
             *
             * @param Mode Mode for incrementation.
             * @param IpString Ip to assign.
             */
            Ipv4(const std::string_view Mode, const std::string_view IpString) {
                this->Mode          = Mode;
                this->IpString      = IpString;
                this->HoldedAddress = GetHoldedAddress();
            }

            //
            // Base funcs.
            //

            /**
             * @brief Set
             *
             * @param Mode Mode Mode for incrementation.
             * @param IpString IpString Ip to assign.
             */
            inline void Set(const std::string_view Mode, const std::string_view IpString) {
                this->Mode          = Mode;
                this->IpString      = IpString;
                this->HoldedAddress = GetHoldedAddress();
            }

            /**
             * @brief Gen
             *
             * This function generates ip address using Mode.
             */
            inline void Gen() {
                srand(time(0));

                IpString.clear();

                IpString += std::to_string(1 + rand() % 255);
                IpString += ".";
                IpString += std::to_string(0 + rand() % 255);
                IpString += ".";
                IpString += std::to_string(0 + rand() % 255);
                IpString += ".";
                IpString += std::to_string(0 + rand() % 255);
            }

            /**
             * @brief Next
             *
             * Increments IpString.
             */
            inline void Next() {
                std::string _1Part, _2Part, _3Part, _4Part;
                unsigned short int Part1, Part2, Part3, Part4;
                unsigned short int PointsInt = 0;

                for (size_t CountPos = 0; CountPos < IpString.length(); CountPos++) {
                    if (IpString[CountPos] == '.') {
                        PointsInt++;

                    } else {
                        if (PointsInt < 1) {
                            _1Part += IpString[CountPos];

                        } else if (PointsInt < 2) {
                            _2Part += IpString[CountPos];

                        } else if (PointsInt < 3) {
                            _3Part += IpString[CountPos];

                        } else {
                            _4Part += IpString[CountPos];
                        }
                    }
                }

                Part1 = boost::lexical_cast<unsigned short int>(_1Part);
                Part2 = boost::lexical_cast<unsigned short int>(_2Part);
                Part3 = boost::lexical_cast<unsigned short int>(_3Part);
                Part4 = boost::lexical_cast<unsigned short int>(_4Part);

                if (Part4 == 255) {
                    Part4 = 0;

                    if (Part3 == 255) {
                        Part3 = 0;

                        if (Part2 == 255) {
                            Part2 = 0;

                            if (Part1 == 255) {
                                Part1 = 0;

                            } else {
                                Part1++;
                            }
                        } else {
                            Part2++;
                        }
                    } else {
                        Part3++;
                    }
                } else {
                    Part4++;
                }

                // Type of mode.
                if (Mode != "all") {
                    if (Mode == "public") { // Public addresses only.
                        // Check for private addresses.
                        if (Part1 == 192) {
                            Part1++;

                        } else if (Part1 == 172) {
                            Part1++;

                        } else if (Part1 == 169) {
                            Part1++;

                        } else if (Part1 == 127) {
                            Part1++;

                        } else if (Part1 == 10) {
                            Part1++;
                        }

                    } else {
                        Hold = true;

                        HoldedAddress = boost::lexical_cast<unsigned short int>(Mode);
                    }
                }

                // Check is address holded.
                if (Hold == true && Part1 != HoldedAddress) {
                    Part1 = HoldedAddress;
                }

                // Compiling to a string.
                IpString = std::to_string(Part1);
                IpString += ".";
                IpString += std::to_string(Part2);
                IpString += ".";
                IpString += std::to_string(Part3);
                IpString += ".";
                IpString += std::to_string(Part4);
            }

            /**
             * @brief Previous
             *
             * Decrements IpString.
             */
            inline void Previous() {
                std::string _1Part, _2Part, _3Part, _4Part;
                unsigned short int Part1, Part2, Part3, Part4;
                int PointsInt = 0;

                for (size_t CountPos = 0; CountPos < IpString.length(); CountPos++) {
                    if (IpString[CountPos] == '.') {
                        PointsInt++;

                    } else {
                        if (PointsInt < 1) {
                            _1Part += IpString[CountPos];

                        } else if (PointsInt < 2) {
                            _2Part += IpString[CountPos];

                        } else if (PointsInt < 3) {
                            _3Part += IpString[CountPos];

                        } else {
                            _4Part += IpString[CountPos];
                        }
                    }
                }

                Part1 = boost::lexical_cast<unsigned short int>(_1Part);
                Part2 = boost::lexical_cast<unsigned short int>(_2Part);
                Part3 = boost::lexical_cast<unsigned short int>(_3Part);
                Part4 = boost::lexical_cast<unsigned short int>(_4Part);

                if (Part4 == 0) {
                    Part4 = 255;

                    if (Part3 == 0) {
                        Part3 = 255;

                        if (Part2 == 0) {
                            Part2 = 255;

                            if (Part1 == 0) {
                                Part1 = 255;

                            } else {
                                Part1--;
                            }
                        } else {
                            Part2--;
                        }
                    } else {
                        Part3--;
                    }
                } else {
                    Part4--;
                }

                // Type of mode.
                if (Mode != "all") {
                    if (Mode == "public") { // Public addresses only.
                        // Check for private addresses.
                        if (Part1 == 192) {
                            Part1++;

                        } else if (Part1 == 172) {
                            Part1++;

                        } else if (Part1 == 169) {
                            Part1++;

                        } else if (Part1 == 127) {
                            Part1++;

                        } else if (Part1 == 10) {
                            Part1++;
                        }

                    } else {
                        Hold = true;

                        if (Mode == "192") {        // only 192.XXX.XXX.XXX.
                            HoldedAddress = 192;

                        } else if (Mode == "172") { // only 172.XXX.XXX.XXX.
                            HoldedAddress = 172;

                        } else if (Mode == "169") { // only 169.XXX.XXX.XXX.
                            HoldedAddress = 169;

                        } else if (Mode == "127") { // only 127.XXX.XXX.XXX.
                            HoldedAddress = 127;

                        } else if (Mode == "10") {  // only  10.XXX.XXX.XXX.
                            HoldedAddress = 10;

                        } else {                    // only ???.XXX.XXX.XXX
                            HoldedAddress = boost::lexical_cast<unsigned short int>(Mode);
                        }
                    }
                }

                // Check is address holded.
                if (Hold == true && Part1 != HoldedAddress) {
                    Part1 = HoldedAddress;
                }

                // Compiling to a string.
                IpString = std::to_string(Part1);
                IpString += ".";
                IpString += std::to_string(Part2);
                IpString += ".";
                IpString += std::to_string(Part3);
                IpString += ".";
                IpString += std::to_string(Part4);
            }

            /**
             * @brief Show
             *
             * @return IpString.
             */
            std::string& Show() {
                return IpString;
            }

        private:
            //
            // Private funcs.
            //

            /**
             * @brief GetHoldedAddress
             *
             * @return Holded address.
             */
            inline unsigned short int GetHoldedAddress() {
                std::string Part1 = "";

                for (size_t y = 0; IpString[y] != '.'; y++) {
                    Part1 += IpString[y];
                }

                return boost::lexical_cast<unsigned short int>(Part1);
            }

            //
            // Private variables.
            //

            std::string        Mode;
            std::string        IpString;
            bool               Hold;
            unsigned short int HoldedAddress;
    };
}

#endif // RED_IPV4_H
