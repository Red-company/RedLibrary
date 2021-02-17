/**
 * @file    InsensitiveMap.h
 * @brief   Definition of InsensitiveMap.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_INSENSITIVEMAP_H
#define RED_INSENSITIVEMAP_H

#include <strings.h>
#include <string>
#include <map>

namespace Red {
    //
    // Private.
    //

    namespace _InsensitiveMap {
        /**
         * @brief CaseInsensitiveComparator
         *
         * Definition of struct which redefines ".at(...)" function into insensitive.
         */
        struct CaseInsensitiveComparator {
            /**
             * @brief operator ()
             *
             * @param a First variable.
             * @param b Second Variable.
             *
             * @return True if First variable equals to second one.
             */
            bool operator()(const std::string& a, const std::string& b) const noexcept {
                return ::strcasecmp(a.c_str(), b.c_str()) < 0;
            }
        };
    }

    //
    // Public.
    //

    /**
     * @brief InsensitiveMap
     *
     * Definition of InsensitiveMap.
     */
    template <typename T1, typename T2>
    using InsensitiveMap = std::map<T1, T2, _InsensitiveMap::CaseInsensitiveComparator>;
}

#endif // RED_INSENSITIVEMAP_H
