/**
 * @file    Transaction.cpp
 * @ingroup RedDataBase
 * @brief   A Transaction is way to group multiple SQL statements into an atomic secured operation.
 *
 * Copyright (c) 2020-forever Vlad Rogozin (vlad.rogozin@bhcc.edu)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "./RedDataBase/Transaction.h"

#include "./RedDataBase/Database.h"
#include "./RedDataBase/Assertion.h"

namespace Red::RedDataBase {
    // Begins the SQLite transaction
    Transaction::Transaction(Database& aDatabase) :
        mDatabase(aDatabase), mbCommited(false) {
            mDatabase.exec("BEGIN");
        }

    // Safely rollback the transaction if it has not been committed.
    Transaction::~Transaction() {
        if (false == mbCommited) {
            try {
                mDatabase.exec("ROLLBACK");
            } catch (RedDataBase::Exception&) {
                // Never throw an exception in a destructor: error if already rollbacked, but no harm is caused by this.
            }
        }
    }

    // Commit the transaction.
    void Transaction::commit() {
        if (false == mbCommited) {
            mDatabase.exec("COMMIT");
            mbCommited = true;
        } else {
            throw RedDataBase::Exception("Transaction already committed.");
        }
    }
}
