/**
 * @file    RedDataBase.h
 * @ingroup RedDataBase
 * @brief   RedDataBase is a smart and simple C++ SQLite3 wrapper. This file is only "easy include" for other files.
 *
 * Include this main header file in your project to gain access to all functionality provided by the wrapper.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef REDDATABSE_INCLUDED
#define REDDATABSE_INCLUDED

#include "../RedLib/RedDataBase/Assertion.h"
#include "../RedLib/RedDataBase/Exception.h"
#include "../RedLib/RedDataBase/Database.h"
#include "../RedLib/RedDataBase/Statement.h"
#include "../RedLib/RedDataBase/Column.h"
#include "../RedLib/RedDataBase/Transaction.h"

/**
 * @brief The [REDDATABASE_VERSION] C preprocessor macro in the RedDataBase.h
 * header evaluates to a string literal that is the RedDataBase version
 * in the format "X.Y.Z" where X is the major version number
 * and Y is the minor version number and Z is the release number.
 *
 * The [REDDATABASE_VERSION_NUMBER] C preprocessor macro resolves to an integer
 * with the value (X*100 + Y*10 + Z) where X, Y, and Z are the same
 * numbers used in [REDDATABASE_VERSION].
 */
#define REDDATABASE_VERSION           "1.0.0"   // 1.0.0
#define REDDATABASE_VERSION_NUMBER     100    // 1.0.0

#endif // REDDATABSE_INCLUDED
