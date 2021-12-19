/**
 * @file    Va1.cpp
 * @brief   Va1 is encryption/decryption lib.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "Va1.h"

#include <string>

class _red_for_Va1 {
    public:
        // Ctor.
        _red_for_Va1() {}

        // Encode function.
        static inline const std::string FirstEncoding(const std::string_view RFirst) {
            std::string Fstep = "";

            for (size_t sybm = 0; sybm < RFirst.length(); sybm++) {
                switch (RFirst[sybm]) {
                case 'l':
                    Fstep += "00";
                    break;
                case 'p':
                    Fstep += "01";
                    break;
                case 'r':
                    Fstep += "02";
                    break;
                case 't':
                    Fstep += "03";
                    break;
                case 'u':
                    Fstep += "04";
                    break;
                case 'd':
                    Fstep += "05";
                    break;
                case 'h':
                    Fstep += "06";
                    break;
                case 'f':
                    Fstep += "07";
                    break;
                case 'c':
                    Fstep += "08";
                    break;
                case 'n':
                    Fstep += "09";
                    break;
                case 'v':
                    Fstep += "10";
                    break;
                case 'w':
                    Fstep += "11";
                    break;
                case 'b':
                    Fstep += "12";
                    break;
                case 'j':
                    Fstep += "13";
                    break;
                case 'o':
                    Fstep += "14";
                    break;
                case 'y':
                    Fstep += "15";
                    break;
                case 'a':
                    Fstep += "16";
                    break;
                case 'z':
                    Fstep += "17";
                    break;
                case 'm':
                    Fstep += "18";
                    break;
                case 'k':
                    Fstep += "19";
                    break;
                case 'x':
                    Fstep += "20";
                    break;
                case 's':
                    Fstep += "21";
                    break;
                case 'q':
                    Fstep += "22";
                    break;
                case 'e':
                    Fstep += "23";
                    break;
                case 'i':
                    Fstep += "24";
                    break;
                case 'g':
                    Fstep += "25";
                    break;
                case '!':
                    Fstep += "26";
                    break;
                case '@':
                    Fstep += "27";
                    break;
                case '(':
                    Fstep += "28";
                    break;
                case '&':
                    Fstep += "29";
                    break;
                case '#':
                    Fstep += "30";
                    break;
                case '%':
                    Fstep += "31";
                    break;
                case '$':
                    Fstep += "32";
                    break;
                case '*':
                    Fstep += "33";
                    break;
                case '^':
                    Fstep += "34";
                    break;
                case ')':
                    Fstep += "35";
                    break;
                case '_':
                    Fstep += "36";
                    break;
                case '+':
                    Fstep += "37";
                    break;
                case '>':
                    Fstep += "38";
                    break;
                case '=':
                    Fstep += "39";
                    break;
                case '<':
                    Fstep += "40";
                    break;
                case '-':
                    Fstep += "41";
                    break;
                case '.':
                    Fstep += "42";
                    break;
                case ',':
                    Fstep += "43";
                    break;
                case ':':
                    Fstep += "44";
                    break;
                case '|':
                    Fstep += "45";
                    break;
                case ';':
                    Fstep += "46";
                    break;
                case '{':
                    Fstep += "47";
                    break;
                case '[':
                    Fstep += "48";
                    break;
                case ']':
                    Fstep += "49";
                    break;
                case '}':
                    Fstep += "50";
                    break;
                case '?':
                    Fstep += "51";
                    break;
                case '"':
                    Fstep += "52";
                    break;
                case ' ':
                    Fstep += "53";
                    break;
                case '`':
                    Fstep += "54";
                    break;
                case '~':
                    Fstep += "55";
                    break;
                case 'G':
                    Fstep += "56";
                    break;
                case '0':
                    Fstep += "57";
                    break;
                case '7':
                    Fstep += "58";
                    break;
                case '5':
                    Fstep += "59";
                    break;
                case '2':
                    Fstep += "60";
                    break;
                case '3':
                    Fstep += "61";
                    break;
                case '1':
                    Fstep += "62";
                    break;
                case '4':
                    Fstep += "63";
                    break;
                case '8':
                    Fstep += "64";
                    break;
                case '6':
                    Fstep += "65";
                    break;
                case '9':
                    Fstep += "66";
                    break;
                case 'L':
                    Fstep += "67";
                    break;
                case 'P':
                    Fstep += "68";
                    break;
                case 'R':
                    Fstep += "69";
                    break;
                case 'T':
                    Fstep += "70";
                    break;
                case 'U':
                    Fstep += "71";
                    break;
                case 'D':
                    Fstep += "72";
                    break;
                case 'H':
                    Fstep += "73";
                    break;
                case 'F':
                    Fstep += "74";
                    break;
                case 'C':
                    Fstep += "75";
                    break;
                case 'N':
                    Fstep += "76";
                    break;
                case 'V':
                    Fstep += "77";
                    break;
                case 'W':
                    Fstep += "78";
                    break;
                case 'B':
                    Fstep += "79";
                    break;
                case 'J':
                    Fstep += "80";
                    break;
                case 'O':
                    Fstep += "81";
                    break;
                case 'Y':
                    Fstep += "82";
                    break;
                case 'A':
                    Fstep += "83";
                    break;
                case 'Z':
                    Fstep += "84";
                    break;
                case 'M':
                    Fstep += "85";
                    break;
                case 'K':
                    Fstep += "86";
                    break;
                case 'X':
                    Fstep += "87";
                    break;
                case 'S':
                    Fstep += "88";
                    break;
                case 'Q':
                    Fstep += "89";
                    break;
                case 'E':
                    Fstep += "90";
                    break;
                case 'I':
                    Fstep += "91";
                    break;
                case '\r':
                    Fstep += "92";
                    break;
                case '\n':
                    Fstep += "93";
                    break;
                case '\t':
                    Fstep += "94";
                    break;
                case '\v':
                    Fstep += "95";
                    break;
                case '\e':
                    Fstep += "96";
                    break;
                case '\0':
                    Fstep += "97";
                    break;
                case '\a':
                    Fstep += "98";
                    break;
                case '\b':
                    Fstep += "99";
                    break;
                case '\f':
                    Fstep += "0a";
                    break;
                case '\\':
                    Fstep += "0b";
                    break;
                case '\'':
                    Fstep += "0c";
                    break;
                default:
                    Fstep += "42"; // point.
                    break;
                }
            }

            return Fstep;
        }

        // Decode function.
        static inline const std::string LastDecoding(const std::string_view RLast) {
            std::string Lstep = "";

            for (size_t symb = 0; symb < RLast.length(); symb+=2) {
                switch (RLast[symb]) {
                case '0':
                    if (RLast[symb+1] == '0') {
                        Lstep += "l";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "p";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "r";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "t";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "u";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "d";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "h";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "f";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "c";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "n";
                    } else if (RLast[symb+1] == 'a') {
                        Lstep += "\f";
                    } else if (RLast[symb+1] == 'b') {
                        Lstep += "\\";
                    } else if (RLast[symb+1] == 'c') {
                        Lstep += "\'";
                    }

                    break;

                case '1':

                    if (RLast[symb+1] == '0') {
                        Lstep += "v";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "w";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "b";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "j";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "o";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "y";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "a";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "z";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "m";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "k";
                    }

                    break;

                case '2':

                    if (RLast[symb+1] == '0') {
                        Lstep += "x";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "s";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "q";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "e";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "i";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "g";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "!";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "@";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "(";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "&";
                    }

                    break;

                case '3':

                    if (RLast[symb+1] == '0') {
                        Lstep += "#";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "%";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "$";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "*";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "^";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += ")";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "_";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "+";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += ">";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "=";
                    }

                    break;

                case '4':

                    if (RLast[symb+1] == '0') {
                        Lstep += "<";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "-";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += ".";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += ",";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += ":";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "|";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += ";";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "{";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "[";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "]";
                    }

                    break;

                case '5':

                    if (RLast[symb+1] == '0') {
                        Lstep += "}";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "?";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "''";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += " ";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "`";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "~";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "G";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "0";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "7";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "5";
                    }

                    break;

                case '6':

                    if (RLast[symb+1] == '0') {
                        Lstep += "2";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "3";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "1";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "4";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "8";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "6";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "9";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "L";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "P";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "R";
                    }

                    break;

                case '7':

                    if (RLast[symb+1] == '0') {
                        Lstep += "T";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "U";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "D";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "H";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "F";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "C";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "N";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "V";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "W";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "B";
                    }

                    break;

                case '8':

                    if (RLast[symb+1] == '0') {
                        Lstep += "J";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "O";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "Y";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "A";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "Z";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "M";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "K";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "X";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "S";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "Q";
                    }

                    break;

                case '9':
                    if (RLast[symb+1] == '0') {
                        Lstep += "E";
                    } else if (RLast[symb+1] == '1') {
                        Lstep += "I";
                    } else if (RLast[symb+1] == '2') {
                        Lstep += "\r";
                    } else if (RLast[symb+1] == '3') {
                        Lstep += "\n";
                    } else if (RLast[symb+1] == '4') {
                        Lstep += "\t";
                    } else if (RLast[symb+1] == '5') {
                        Lstep += "\v";
                    } else if (RLast[symb+1] == '6') {
                        Lstep += "\e";
                    } else if (RLast[symb+1] == '7') {
                        Lstep += "\0";
                    } else if (RLast[symb+1] == '8') {
                        Lstep += "\a";
                    } else if (RLast[symb+1] == '9') {
                        Lstep += "\b";
                    }

                    break;

                default:
                    Lstep += "..";
                    break;
                }
            }

            return Lstep;
        }

        // Dtor.
        ~_red_for_Va1() {}
};

/**
 * @brief Va1Encode
 *
 * @param ToEnc String to be encoded.
 *
 * @return Encoded string.
 */
const std::string Red::Va1Encode(const std::string_view ToEnc) {
    return _red_for_Va1::FirstEncoding(ToEnc);
}

/**
 * @brief Va1Decode
 *
 * @param ToDec String to be decoded.
 *
 * @return Decoded string.
 */
const std::string Red::Va1Decode(const std::string_view ToDec) {
    return _red_for_Va1::LastDecoding(ToDec);
}
