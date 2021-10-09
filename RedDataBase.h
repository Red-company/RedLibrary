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
#ifndef RED_DATABSE_H
#define RED_DATABSE_H

#include "./RedDataBase/Assertion.h"
#include "./RedDataBase/Exception.h"
#include "./RedDataBase/Database.h"
#include "./RedDataBase/Statement.h"
#include "./RedDataBase/Column.h"
#include "./RedDataBase/Transaction.h"
#include "./RedDataBase/Check.h"

#define REDDATABASE_VERSION           "1.0"
#define REDDATABASE_VERSION_NUMBER     10

#endif // RED_DATABASE_H
