/**
 * @file    Backup.cpp
 * @ingroup RedDataBase
 * @brief   Backup is used to backup a database file in a safe and online way.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "./RedDataBase/Backup.h"

#include "./RedDataBase/Exception.h"

#include <sqlite3.h>

namespace Red::RedDataBase {
    // Initialize resource for SQLite database backup
    Backup::Backup(Database& aDestDatabase, const char* apDestDatabaseName,
                   Database& aSrcDatabase, const char* apSrcDatabaseName) {
        mpSQLiteBackup = sqlite3_backup_init(aDestDatabase.getHandle(), apDestDatabaseName,
                                             aSrcDatabase.getHandle(), apSrcDatabaseName);
        if (nullptr == mpSQLiteBackup) {
            // If an error occurs, the error code and message are attached to the destination database connection.
            throw RedDataBase::Exception(aDestDatabase.getHandle());
        }
    }

    Backup::Backup(Database& aDestDatabase, const std::string& aDestDatabaseName,
                   Database& aSrcDatabase, const std::string&   aSrcDatabaseName) :
    Backup(aDestDatabase, aDestDatabaseName.c_str(), aSrcDatabase, aSrcDatabaseName.c_str()) {}

    Backup::Backup(Database &aDestDatabase, Database &aSrcDatabase) :
        Backup(aDestDatabase, "main", aSrcDatabase, "main") {}

    /// Release the RedDataBase Backup resource.
    Backup::~Backup() {
        if (mpSQLiteBackup) {
            sqlite3_backup_finish(mpSQLiteBackup);
        }

        mpSQLiteBackup = nullptr;
    }

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
    int Backup::executeStep(const int aNumPage /* = -1 */) {
        const int res = sqlite3_backup_step(mpSQLiteBackup, aNumPage);

        if (SQLITE_OK != res && SQLITE_DONE != res && SQLITE_BUSY != res && SQLITE_LOCKED != res) {
            throw RedDataBase::Exception(sqlite3_errstr(res), res);
        }

        return res;
    }

    /**
     * @brief getRemainingPageCount
     *
     * @return Number of source pages still to be backed up as of the most recent call to executeStep().
     */
    int Backup::getRemainingPageCount() {
        return sqlite3_backup_remaining(mpSQLiteBackup);
    }

    /**
     * @brief getTotalPageCount
     *
     * @return Total number of pages in the source database as of the most recent call to executeStep().
     */
    int Backup::getTotalPageCount() {
        return sqlite3_backup_pagecount(mpSQLiteBackup);
    }
}
