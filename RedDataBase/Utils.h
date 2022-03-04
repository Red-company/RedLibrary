/**
 * @file    Utils.h
 * @ingroup RedDataBase
 * @brief   Definition of the REDDATABASE_PURE_FUNC macro.
 *
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_DATABASE_UTILS_H
#define RED_DATABASE_UTILS_H

// macro taken from https://github.com/nemequ/hedley/blob/master/hedley.h that was in public domain at this time
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__) ||\
(defined(__INTEL_COMPILER) && __INTEL_COMPILER > 1600) ||\
(defined(__ARMCC_VERSION) && __ARMCC_VERSION > 4010000) ||\
(\
    defined(__TI_COMPILER_VERSION__) && (\
        __TI_COMPILER_VERSION__ > 8003000 ||\
        (__TI_COMPILER_VERSION__ > 7003000 && defined(__TI_GNU_ATTRIBUTE_SUPPORT__))\
    )\
)
#if defined(__has_attribute)
#if !defined(REDDATABASE_PURE_FUNC) && __has_attribute(pure)
#define REDDATABASE_PURE_FUNC __attribute__((pure))
#endif
#endif
#endif
#if !defined(REDDATABASE_PURE_FUNC)
#define REDDATABASE_PURE_FUNC
#endif

#endif // RED_DATABASE_UTILS_H
