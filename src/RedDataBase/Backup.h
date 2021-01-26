/**
 * @file    Backup.h
 * @ingroup RedDataBase
 * @brief   Backup is used to backup a database file in a safe and online way.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_DATABASE_BACKUP_H
#define BACKUP_H

#include "./RedDataBase/Database.h"

#include <string>

// Forward declaration to avoid inclusion of <sqlite3.h> in a header
struct sqlite3_backup;

namespace RedDataBase {
    /**
     * @brief RAII encapsulation of a RedDataBase Backup process.
     *
     * A Backup object is used to backup a source database file to a destination database file
     * in a safe and online way.
     *
     * See also the a reference implementation of live backup taken from the official site:
     * https://www.sqlite.org/backup.html
     */
    class Backup {
        public:
            /**
             * @brief Initialize a RedDataBase Backup object.
             *
             * Initialize a RedDataBase Backup object for the source database and destination database.
             * The database name is "main" for the main database, "temp" for the temporary database,
             * or the name specified after the AS keyword in an ATTACH statement for an attached database.
             *
             * Exception is thrown in case of error, then the Backup object is NOT constructed.
             *
             * @param[in] aDestDatabase        Destination database connection
             * @param[in] apDestDatabaseName   Destination database name
             * @param[in] aSrcDatabase         Source database connection
             * @param[in] apSrcDatabaseName    Source database name
             *
             * @throw RedDataBase::Exception in case of error
             */
            Backup(Database& aDestDatabase, const char* apDestDatabaseName,
                   Database& aSrcDatabase, const char* apSrcDatabaseName);

            /**
             * @brief Initialize a RedDataBase Backup object.
             *
             * Initialize a RedDataBase Backup object for source database and destination database.
             * The database name is "main" for the main database, "temp" for the temporary database,
             * or the name specified after the AS keyword in an ATTACH statement for an attached database.
             *
             * Exception is thrown in case of error, then the Backup object is NOT constructed.
             *
             * @param[in] aDestDatabase        Destination database connection
             * @param[in] aDestDatabaseName    Destination database name
             * @param[in] aSrcDatabase         Source database connection
             * @param[in] aSrcDatabaseName     Source database name
             *
             * @throw RedDataBase::Exception in case of error
             */
            Backup(Database& aDestDatabase, const std::string& aDestDatabaseName,
                   Database& aSrcDatabase, const std::string& aSrcDatabaseName);

            /**
             * @brief Initialize a RedDataBase Backup object for main databases.
             *
             * Initialize a RedDataBase Backup object for source database and destination database.
             * Backup the main databases between the source and the destination.
             *
             * Exception is thrown in case of error, then the Backup object is NOT constructed.
             *
             * @param[in] aDestDatabase        Destination database connection
             * @param[in] aSrcDatabase         Source database connection
             *
             * @throw RedDataBase::Exception in case of error
             */
            Backup(Database& aDestDatabase, Database& aSrcDatabase);

            // Backup is non-copyable
            Backup(const Backup&) = delete;
            Backup& operator=(const Backup&) = delete;

            /// Release the RedDataBase Backup resource.
            ~Backup();

            /**
             * @brief Execute a step of backup with a given number of source pages to be copied
             *
             * Exception is thrown when SQLITE_IOERR_XXX, SQLITE_NOMEM, or SQLITE_READONLY is returned
             * in sqlite3_backup_step(). These errors are considered fatal, so there is no point
             * in retrying the call to executeStep().
             *
             * @param[in] aNumPage    The number of source pages to be copied, with a negative value meaning all remaining source pages
             *
             * @return REDDATABASE_OK/REDDATABASE_DONE/REDDATABASE_BUSY/REDDATABASE_LOCKED
             *
             * @throw RedDataBase::Exception in case of error
             */
            int executeStep(const int aNumPage = -1);

            /// Return the number of source pages still to be backed up as of the most recent call to executeStep().
            int getRemainingPageCount();

            /// Return the total number of pages in the source database as of the most recent call to executeStep().
            int getTotalPageCount();

        private:
            // TODO: use std::unique_ptr with a custom deleter to call sqlite3_backup_finish()
            sqlite3_backup* mpSQLiteBackup = nullptr;   ///< Pointer to Database Backup Handle
    };
}

#endif // RED_DATABASE_BACKUP_H
