/**
 * @file    Transaction.h
 * @ingroup RedDataBase
 * @brief   A Transaction is way to group multiple SQL statements into an atomic secured operation.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_DATABASE_TRANSACTION_H
#define RED_DATABASE_TRANSACTION_H

#include "./RedDataBase/Exception.h"

namespace RedDataBase {
    // Forward declaration
    class Database;

    /**
     * @brief RAII encapsulation of a SQLite Transaction.
     *
     * A Transaction is a way to group multiple SQL statements into an atomic secured operation;
    * either it succeeds, with all the changes committed to the database file,
     * or if it fails, all the changes are rolled back to the initial state.
     *
     * Resource Acquisition Is Initialization (RAII) means that the Transaction
     * begins in the constructor and is rollbacked in the destructor, so that there is
     * no need to worry about memory management or the validity of the underlying SQLite Connection.
     *
     * This method also offers big performances improvements compared to individually executed statements.
     *
     * Thread-safety: a Transaction object shall not be shared by multiple threads, because :
     * 1) in the SQLite "Thread Safe" mode, "SQLite can be safely used by multiple threads
     *    provided that no single database connection is used simultaneously in two or more threads."
     * 2) the SQLite "Serialized" mode is not supported by RedDataBase,
     *    because of the way it shares the underling SQLite precompiled statement
     *    in a custom shared pointer (See the inner class "Statement::Ptr").
     */
    class Transaction {
        public:
            /**
             * @brief Begins the SQLite transaction
             *
             * @param[in] aDatabase the SQLite Database Connection
             *
             * Exception is thrown in case of error, then the Transaction is NOT initiated.
             */
            explicit Transaction(Database& aDatabase);

            // Transaction is non-copyable
            Transaction(const Transaction&) = delete;
            Transaction& operator=(const Transaction&) = delete;

            /**
             * @brief Safely rollback the transaction if it has not been committed.
             */
            ~Transaction();

            /**
             * @brief Commit the transaction.
             */
            void commit();

        private:
            Database&   mDatabase;  ///< Reference to the SQLite Database Connection
            bool        mbCommited; ///< True when commit has been called
    };
}

#endif // RED_DATABASE_TRANSACTION_H