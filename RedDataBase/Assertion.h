/**
 * @file    Assertion.h
 * @ingroup RedDataBase
 * @brief   Definition of the REDDATABASE_ASSERT() macro.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_DATABASE_ASSERTION_H
#define RED_DATABASE_ASSERTION_H

#include <cassert>

/**
 * REDDATABASE_ASSERT, REDDATABASE_ASSERT() is used in destructors, where exceptions shall not be thrown
 *
 * Define REDDATABASE_ENABLE_ASSERT_HANDLER at the project level
 * and define a RedDataBase::assertion_failed() assertion handler
 * to tell RedDataBase to use it instead of assert() when an assertion fail.
*/
#ifdef REDDATABASE_ENABLE_ASSERT_HANDLER
// if an assert handler is provided by user code, use it instead of assert()
namespace RedDataBase {
    // declaration of the assert handler to define in user code
    void assertion_failed(const char* apFile, const long apLine, const char* apFunc,
                          const char* apExpr, const char* apMsg);

    #ifdef _MSC_VER
    #define __func__ __FUNCTION__
    #endif
    // call the assert handler provided by user code
    #define REDDATABASE_ASSERT(expression, message) \
    if (!(expression)) { SQLite::assertion_failed(__FILE__, __LINE__, __func__, #expression, message) }
}

#else
// if no assert handler provided by user code, use standard assert()
// (note: in release mode assert() does nothing)
#define REDDATABASE_ASSERT(expression, message)   assert(expression && message)
#endif

#endif // RED_DATABASE_ASSERTION_H
