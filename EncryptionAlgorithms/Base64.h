/**
 * @file    Base64.h
 * @brief   Base64 is string encryption/decryption lib.
 *
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_BASE64_H
#define RED_BASE64_H

#include <algorithm>
#include <string>

// Version.
#define REDBASE64_VERSION "1.1" // There was no v1.0 macros.

namespace Red {
    /**
     * @brief get_base64_chars
     *
     * @return Base64 chars.
     */
    inline std::string get_base64_chars() {
        static std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                          "abcdefghijklmnopqrstuvwxyz"
                                          "0123456789+/";

        return base64_chars;
    }

    /**
     * @brief Base64Encode
     *
     * @param data String to be encoded.
     *
     * @return Base64 string.
     */
    inline std::string * Base64Encode(std::string *data) {
        int      counter = 0;
        uint32_t bit_stream = 0;

        const std::string base64_chars = get_base64_chars();

        // For result.
        std::string *encoded = new std::string;

        int offset = 0;

        for (unsigned char c : *data) {
            auto num_val = static_cast<unsigned int>(c);

            offset = 16 - counter % 3 * 8;
            bit_stream += num_val << offset;

            if (offset == 16) {
                *encoded += base64_chars.at(bit_stream >> 18 & 0x3f);
            }

            if (offset == 8) {
                *encoded += base64_chars.at(bit_stream >> 12 & 0x3f);
            }

            if (offset == 0 && counter != 3) {
                *encoded += base64_chars.at(bit_stream >> 6 & 0x3f);
                *encoded += base64_chars.at(bit_stream & 0x3f);
                bit_stream = 0;
            }

            counter++;
        }

        if (offset == 16) {
            *encoded += base64_chars.at(bit_stream >> 12 & 0x3f);
            *encoded += "==";
        }

        if (offset == 8) {
            *encoded += base64_chars.at(bit_stream >> 6 & 0x3f);
            *encoded += '=';
        }

        return encoded;
    }

    /**
     * @brief Base64Decode
     *
     * @param data Base64 string.
     *
     * @return Decoded string.
     */
    inline std::string * Base64Decode(std::string *data) {
      int      counter = 0;
      uint32_t bit_stream = 0;

      // For result.
      std::string *decoded = new std::string;

      int offset = 0;

      const std::string base64_chars = get_base64_chars();

      for (unsigned char c : *data) {
          auto num_val = base64_chars.find(c);

          if (num_val != std::string::npos) {
              offset = 18 - counter % 4 * 6;
              bit_stream += num_val << offset;

              if (offset == 12) {
                  *decoded += static_cast<char>(bit_stream >> 16 & 0xff);
              }

              if (offset == 6) {
                  *decoded += static_cast<char>(bit_stream >> 8 & 0xff);
              }

              if (offset == 0 && counter != 4) {
                  *decoded += static_cast<char>(bit_stream & 0xff);
                  bit_stream = 0;
              }

          }

          counter++;
      }

      return decoded;
    }
}

#endif //RED_BASE64_H
