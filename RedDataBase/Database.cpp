/**
 * @file    Database.cpp
 * @ingroup RedDataBase
 * @brief   Management of a SQLite Database Connection.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "./RedDataBase/Database.h"

#include "./RedDataBase/Assertion.h"
#include "./RedDataBase/Backup.h"
#include "./RedDataBase/Exception.h"
#include "./RedDataBase/Statement.h"

#include <sqlite3.h>
#include <fstream>
#include <string.h>

#ifndef SQLITE_DETERMINISTIC
#define SQLITE_DETERMINISTIC 0x800
#endif // SQLITE_DETERMINISTIC

namespace Red::RedDataBase {
    const int   OPEN_READONLY   = SQLITE_OPEN_READONLY;
    const int   OPEN_READWRITE  = SQLITE_OPEN_READWRITE;
    const int   OPEN_CREATE     = SQLITE_OPEN_CREATE;
    const int   OPEN_URI        = SQLITE_OPEN_URI;
    const int   OPEN_FULLMUTEX  = SQLITE_OPEN_FULLMUTEX;

    const int   OK              = SQLITE_OK;

    const char* VERSION         = SQLITE_VERSION;
    const int   VERSION_NUMBER  = SQLITE_VERSION_NUMBER;

    // Return SQLite version string using runtime call to the compiled library
    const char* getLibVersion() noexcept {
        return sqlite3_libversion();
    }

    // Return SQLite version number using runtime call to the compiled library
    int getLibVersionNumber() noexcept {
        return sqlite3_libversion_number();
    }


    // Open the provided database UTF-8 filename with RedDataBase::OPEN_xxx provided flags.
    Database::Database(const char* apFilename, const int   aFlags /* = RedDataBase::OPEN_READONLY*/,
                       const int   aBusyTimeoutMs /* = 0 */, const char* apVfs /* = nullptr*/) :
                                                                            mFilename(apFilename) {
        sqlite3* handle;
        const int ret = sqlite3_open_v2(apFilename, &handle, aFlags, apVfs);
        mSQLitePtr.reset(handle);

        if (SQLITE_OK != ret) {
            throw RedDataBase::Exception(handle, ret);
        }

        if (aBusyTimeoutMs > 0) {
            setBusyTimeout(aBusyTimeoutMs);
        }
    }

    // Deleter functor to use with smart pointers to close the SQLite database connection in an RAII fashion.
    void Database::Deleter::operator()(sqlite3* apSQLite) {
        const int ret = sqlite3_close(apSQLite); // Calling sqlite3_close() with a nullptr argument is a harmless no-op.

        // Avoid unreferenced variable warning when build in release mode
        (void) ret;

        // Only case of error is REDDATABASE_BUSY: "database is locked" (some statements are not finalized)
        // Never throw an exception in a destructor :
        REDDATABASE_ASSERT(SQLITE_OK == ret, "database is locked");  // See REDDATABASE_ENABLE_ASSERT_HANDLER
    }

    /**
     * @brief Set a busy handler that sleeps for a specified amount of time when a table is locked.
     *
     *  This is useful in multithreaded program to handle case where a table is locked for writting by a thread.
     *  Any other thread cannot access the table and will receive a REDDATABASE_BUSY error:
     *  setting a timeout will wait and retry up to the time specified before returning this REDDATABASE_BUSY error.
     *  Reading the value of timeout for current connection can be done with SQL query "PRAGMA busy_timeout;".
     *  Default busy timeout is 0ms.
     *
     * @param[in] aBusyTimeoutMs    Amount of milliseconds to wait before returning REDDATABASE_BUSY
     *
     * @throw RedDataBase::Exception in case of error
     */
    void Database::setBusyTimeout(const int aBusyTimeoutMs) {
        const int ret = sqlite3_busy_timeout(getHandle(), aBusyTimeoutMs);
        check(ret);
    }

    /**
     * @brief Shortcut to execute one or multiple statements without results.
     *
     *  This is useful for any kind of statements other than the Data Query Language (DQL) "SELECT" :
     *  - Data Manipulation Language (DML) statements "INSERT", "UPDATE" and "DELETE"
     *  - Data Definition Language (DDL) statements "CREATE", "ALTER" and "DROP"
     *  - Data Control Language (DCL) statements "GRANT", "REVOKE", "COMMIT" and "ROLLBACK"
     *
     * @see Database::tryExec() to execute, returning the sqlite result code
     * @see Statement::exec() to handle precompiled statements (for better performances) without results
     * @see Statement::executeStep() to handle "SELECT" queries with results
     *
     * @param[in] apQueries  one or multiple UTF-8 encoded, semicolon-separate SQL statements
     *
     * @return number of rows modified by the *last* INSERT, UPDATE or DELETE statement (beware of multiple statements)
     * @warning undefined for CREATE or DROP table: returns the value of a previous INSERT, UPDATE or DELETE statement.
     *
     * @throw RedDataBase::Exception in case of error
     */
    int Database::exec(const char* apQueries) {
        const int ret = tryExec(apQueries);
        check(ret);

        // Return the number of rows modified by those SQL statements (INSERT, UPDATE or DELETE only)
        return sqlite3_changes(getHandle());
    }

    /**
     * @brief Try to execute one or multiple statements, returning the sqlite result code.
     *
     *  This is useful for any kind of statements other than the Data Query Language (DQL) "SELECT" :
     *  - Data Manipulation Language (DML) statements "INSERT", "UPDATE" and "DELETE"
     *  - Data Definition Language (DDL) statements "CREATE", "ALTER" and "DROP"
     *  - Data Control Language (DCL) statements "GRANT", "REVOKE", "COMMIT" and "ROLLBACK"
     *
     * @see exec() to execute, returning number of rows modified
     *
     * @param[in] aQueries  one or multiple UTF-8 encoded, semicolon-separate SQL statements
     *
     * @return the sqlite result code.
     */
    int Database::tryExec(const char* apQueries) noexcept {
        return sqlite3_exec(getHandle(), apQueries, nullptr, nullptr, nullptr);
    }

    /**
     * @brief Shortcut to execute a one step query and fetch the first column of the result.
     *
     *  This is a shortcut to execute a simple statement with a single result.
     * This should be used only for non reusable queries (else you should use a Statement with bind()).
     * This should be used only for queries with expected results (else an exception is fired).
     *
     * @warning WARNING: Be very careful with this dangerous method: you have to
     *          make a COPY OF THE result, else it will be destroy before the next line
     *          (when the underlying temporary Statement and Column objects are destroyed)
     *
     * @see also Statement class for handling queries with multiple results
     *
     * @param[in] apQuery  an UTF-8 encoded SQL query
     *
     * @return a temporary Column object with the first column of result.
     *
     * @throw RedDataBase::Exception in case of error
     */
    Column Database::execAndGet(const char* apQuery) {
        Statement query(*this, apQuery);
        (void)query.executeStep(); // Can return false if no result, which will throw next line in getColumn()
        return query.getColumn(0);
    }

    /**
     * @brief Shortcut to test if a table exists.
     *
     *  Table names are case sensitive.
     *
     * @param[in] apTableName an UTF-8 encoded case sensitive Table name
     *
     * @return true if the table exists.
     *
     * @throw RedDataBase::Exception in case of error
     */
    bool Database::tableExists(const char* apTableName) {
        Statement query(*this, "SELECT count(*) FROM sqlite_master WHERE type='table' AND name=?");
        query.bind(1, apTableName);
        (void)query.executeStep(); // Cannot return false, as the above query always return a result
        return (1 == query.getColumn(0).getInt());
    }

    /**
     * @brief Get the rowid of the most recent successful INSERT into the database from the current connection.
     *
     *  Each entry in an SQLite table always has a unique 64-bit signed integer key called the rowid.
     * If the table has a column of type INTEGER PRIMARY KEY, then it is an alias for the rowid.
     *
     * @return Rowid of the most recent successful INSERT into the database, or 0 if there was none.
     */
    long long Database::getLastInsertRowid() const noexcept {
        return sqlite3_last_insert_rowid(getHandle());
    }

    // Get total number of rows modified by all INSERT, UPDATE or DELETE statement since connection.
    int Database::getTotalChanges() const noexcept {
        return sqlite3_total_changes(getHandle());
    }

    // Return the numeric result code for the most recent failed API call (if any).
    int Database::getErrorCode() const noexcept {
        return sqlite3_errcode(getHandle());
    }

    // Return the extended numeric result code for the most recent failed API call (if any).
    int Database::getExtendedErrorCode() const noexcept {
        return sqlite3_extended_errcode(getHandle());
    }

    // Return UTF-8 encoded English language explanation of the most recent failed API call (if any).
    const char* Database::getErrorMsg() const noexcept {
        return sqlite3_errmsg(getHandle());
    }

    /**
     * @brief Create or redefine a SQL function or aggregate in the sqlite database.
     *
     *  This is the equivalent of the sqlite3_create_function_v2 command.
     * @see http://www.sqlite.org/c3ref/create_function.html
     *
     * @note UTF-8 text encoding assumed.
     *
     * @param[in] apFuncName    Name of the SQL function to be created or redefined
     * @param[in] aNbArg        Number of arguments in the function
     * @param[in] abDeterministic Optimize for deterministic functions (most are). A random number generator is not.
     * @param[in] apApp         Arbitrary pointer of user data, accessible with sqlite3_user_data().
     * @param[in] apFunc        Pointer to a C-function to implement a scalar SQL function (apStep & apFinal nullptr)
     * @param[in] apStep        Pointer to a C-function to implement an aggregate SQL function (apFunc nullptr)
     * @param[in] apFinal       Pointer to a C-function to implement an aggregate SQL function (apFunc nullptr)
     * @param[in] apDestroy     If not nullptr, then it is the destructor for the application data pointer.
     *
     * @throw RedDataBase::Exception in case of error
     */
    void Database::createFunction(const char* apFuncName, int aNbArg, bool abDeterministic, void* apApp,
                                  void (*apFunc)(sqlite3_context *, int, sqlite3_value **),
                                  void (*apStep)(sqlite3_context *, int, sqlite3_value **) /* = nullptr */,
                                  void (*apFinal)(sqlite3_context *) /* = nullptr */, // NOLINT(readability/casting)
                                  void (*apDestroy)(void *) /* = nullptr */) {
        int textRep = SQLITE_UTF8;

        // optimization if deterministic function (e.g. of nondeterministic function random())
        if (abDeterministic) {
            textRep = textRep | SQLITE_DETERMINISTIC;
        }

        const int ret = sqlite3_create_function_v2(getHandle(), apFuncName, aNbArg, textRep,
                                               apApp, apFunc, apStep, apFinal, apDestroy);
        check(ret);
    }

    /**
     * @brief Load a module into the current sqlite database instance.
     *
     *  This is the equivalent of the sqlite3_load_extension call, but additionally enables
     *  module loading support prior to loading the requested module.
     *
     * @see http://www.sqlite.org/c3ref/load_extension.html
     *
     * @note UTF-8 text encoding assumed.
     *
     * @param[in] apExtensionName   Name of the shared library containing extension
     * @param[in] apEntryPointName  Name of the entry point (nullptr to let sqlite work it out)
     *
     * @throw RedDataBase::Exception in case of error
     */
    void Database::loadExtension(const char* apExtensionName, const char *apEntryPointName) {
        #ifdef SQLITE_OMIT_LOAD_EXTENSION
        // Unused
        (void)apExtensionName;
        (void)apEntryPointName;

        throw RedDataBase::Exception("sqlite extensions are disabled");
        #else
        #ifdef SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION // Since SQLite 3.13 (2016-05-18):
        // Security warning:
        // It is recommended that the SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION method be used to enable only this interface.
        // The use of the sqlite3_enable_load_extension() interface should be avoided to keep the SQL load_extension()
        // disabled and prevent SQL injections from giving attackers access to extension loading capabilities.
        // (NOTE: not using nullptr: cannot pass object of non-POD type 'std::__1::nullptr_t' through variadic function)
        int ret = sqlite3_db_config(getHandle(), SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION, 1, NULL); // NOTE: not using nullptr
        #else
        int ret = sqlite3_enable_load_extension(getHandle(), 1);
        #endif
        check(ret);

        ret = sqlite3_load_extension(getHandle(), apExtensionName, apEntryPointName, nullptr);
        check(ret);
        #endif
    }

    /**
     * @brief Set the key for the current sqlite database instance.
     *
     *  This is the equivalent of the sqlite3_key call and should thus be called
     *  directly after opening the database.
     *  Open encrypted database -> call db.key("secret") -> database ready
     *
     * @param[in] aKey   Key to decode/encode the database
     *
     * @throw RedDataBase::Exception in case of error
     */
    void Database::key(const std::string& aKey) const {
        int passLen = static_cast<int>(aKey.length());
        #ifdef SQLITE_HAS_CODEC
        if (passLen > 0) {
            const int ret = sqlite3_key(getHandle(), aKey.c_str(), passLen);
            check(ret);
        }
        #else // SQLITE_HAS_CODEC
        if (passLen > 0) {
            throw RedDataBase::Exception("No encryption support, recompile with SQLITE_HAS_CODEC to enable.");
        }
        #endif // SQLITE_HAS_CODEC
    }

    /**
     * @brief Reset the key for the current sqlite database instance.
     *
     *  This is the equivalent of the sqlite3_rekey call and should thus be called
     *  after the database has been opened with a valid key. To decrypt a
     *  database, call this method with an empty string.
     *  Open normal database -> call db.rekey("secret") -> encrypted database, database ready
     *  Open encrypted database -> call db.key("secret") -> call db.rekey("newsecret") -> change key, database ready
     *  Open encrypted database -> call db.key("secret") -> call db.rekey("") -> decrypted database, database ready
     *
     * @param[in] aNewKey   New key to encode the database
     *
     * @throw RedDataBase::Exception in case of error
     */
    void Database::rekey(const std::string& aNewKey) const {
        #ifdef SQLITE_HAS_CODEC
        int passLen = aNewKey.length();

        if (passLen > 0) {
            const int ret = sqlite3_rekey(getHandle(), aNewKey.c_str(), passLen);
            check(ret);
        } else {
            const int ret = sqlite3_rekey(getHandle(), nullptr, 0);
            check(ret);
        }
        #else // SQLITE_HAS_CODEC
        static_cast<void>(aNewKey); // silence unused parameter warning
        throw RedDataBase::Exception("No encryption support, recompile with SQLITE_HAS_CODEC to enable.");
        #endif // SQLITE_HAS_CODEC
    }

    /**
     * @brief Test if a file contains an unencrypted database.
     *
     *  This is a simple test that reads the first bytes of a database file and
     *  compares them to the standard header for unencrypted databases. If the
     *  header does not match the standard string, we assume that we have an
     *  encrypted file.
     *
     * @param[in] aFilename path/uri to a file
     *
     * @return true if the database has the standard header.
     *
     * @throw RedDataBase::Exception in case of error
     */
    bool Database::isUnencrypted(const std::string& aFilename) {
        if (aFilename.empty()) {
            throw RedDataBase::Exception("Could not open database, the aFilename parameter was empty.");
        }

        std::ifstream fileBuffer(aFilename.c_str(), std::ios::in | std::ios::binary);
        char header[16];

        if (fileBuffer.is_open()) {
            fileBuffer.seekg(0, std::ios::beg);
            fileBuffer.getline(header, 16);
            fileBuffer.close();
        } else {
            throw RedDataBase::Exception("Error opening file: " + aFilename);
        }

        return strncmp(header, "SQLite format 3\000", 16) == 0;
    }

    /**
     * @brief Parse SQLite header data from a database file.
     *
     *  This function reads the first 100 bytes of a SQLite database file
     *  and reconstructs groups of individual bytes into the associated fields
     *  in a Header object.
     *
     * @param[in] aFilename path/uri to a file
     *
     * @return Header object containing file data
     *
     * @throw RedDataBase::Exception in case of error
     */
    Header Database::getHeaderInfo(const std::string& aFilename) {
        Header h;
        unsigned char buf[100];
        char* pBuf = reinterpret_cast<char*>(&buf[0]);
        char* pHeaderStr = reinterpret_cast<char*>(&h.headerStr[0]);

        if (aFilename.empty()) {
            throw RedDataBase::Exception("Filename parameter is empty");
        }

        {
            std::ifstream fileBuffer(aFilename.c_str(), std::ios::in | std::ios::binary);
            if (fileBuffer.is_open()) {
                fileBuffer.seekg(0, std::ios::beg);
                fileBuffer.read(pBuf, 100);
                fileBuffer.close();

                if (fileBuffer.gcount() < 100) {
                    throw RedDataBase::Exception("File " + aFilename + " is too short");
                }
            } else {
                throw RedDataBase::Exception("Error opening file " + aFilename);
            }
        }

        // If the "magic string" can't be found then header is invalid, corrupt or unreadable
        memcpy(pHeaderStr, pBuf, 16);
        pHeaderStr[15] = '\0';

        if (strncmp(pHeaderStr, "SQLite format 3", 15) != 0) {
            throw RedDataBase::Exception("Invalid or encrypted SQLite header in file " + aFilename);
        }

        h.pageSizeBytes = (buf[16] << 8) | buf[17];
        h.fileFormatWriteVersion = buf[18];
        h.fileFormatReadVersion = buf[19];
        h.reservedSpaceBytes = buf[20];
        h.maxEmbeddedPayloadFrac = buf[21];
        h.minEmbeddedPayloadFrac = buf[22];
        h.leafPayloadFrac = buf[23];

        h.fileChangeCounter =
            (buf[24] << 24) |
            (buf[25] << 16) |
            (buf[26] << 8)  |
            (buf[27] << 0);

        h.databaseSizePages =
            (buf[28] << 24) |
            (buf[29] << 16) |
            (buf[30] << 8)  |
            (buf[31] << 0);

        h.firstFreelistTrunkPage =
            (buf[32] << 24) |
            (buf[33] << 16) |
            (buf[34] << 8)  |
            (buf[35] << 0);

        h.totalFreelistPages =
            (buf[36] << 24) |
            (buf[37] << 16) |
            (buf[38] << 8)  |
            (buf[39] << 0);

        h.schemaCookie =
            (buf[40] << 24) |
            (buf[41] << 16) |
            (buf[42] << 8)  |
            (buf[43] << 0);

        h.schemaFormatNumber =
            (buf[44] << 24) |
            (buf[45] << 16) |
            (buf[46] << 8)  |
            (buf[47] << 0);

        h.defaultPageCacheSizeBytes =
            (buf[48] << 24) |
            (buf[49] << 16) |
            (buf[50] << 8)  |
            (buf[51] << 0);

        h.largestBTreePageNumber =
            (buf[52] << 24) |
            (buf[53] << 16) |
            (buf[54] << 8)  |
            (buf[55] << 0);

        h.databaseTextEncoding =
            (buf[56] << 24) |
            (buf[57] << 16) |
            (buf[58] << 8)  |
            (buf[59] << 0);

        h.userVersion =
            (buf[60] << 24) |
            (buf[61] << 16) |
            (buf[62] << 8)  |
            (buf[63] << 0);

        h.incrementalVaccumMode =
            (buf[64] << 24) |
            (buf[65] << 16) |
            (buf[66] << 8)  |
            (buf[67] << 0);

        h.applicationId =
            (buf[68] << 24) |
            (buf[69] << 16) |
            (buf[70] << 8)  |
            (buf[71] << 0);

        h.versionValidFor =
            (buf[92] << 24) |
            (buf[93] << 16) |
            (buf[94] << 8)  |
            (buf[95] << 0);

        h.sqliteVersion =
            (buf[96] << 24) |
            (buf[97] << 16) |
            (buf[98] << 8)  |
            (buf[99] << 0);

        return h;
    }

    /**
     * @brief Load or save the database content.
     *
     * This function is used to load the contents of a database file on disk
     * into the "main" database of open database connection, or to save the current
     * contents of the database into a database file on disk.
     *
     * @throw RedDataBase::Exception in case of error
     */
    void Database::backup(const char* apFilename, BackupType aType) {
        // Open the database file identified by apFilename
        Database otherDatabase(apFilename, RedDataBase::OPEN_READWRITE | RedDataBase::OPEN_CREATE);

        // For a 'Save' operation, data is copied from the current Database to the other. A 'Load' is the reverse.
        Database& src = (aType == Save ? *this : otherDatabase);
        Database& dest = (aType == Save ? otherDatabase : *this);

        // Set up the backup procedure to copy between the "main" databases of each connection
        Backup bkp(dest, src);
        bkp.executeStep(); // Execute all steps at once

        // RAII Finish Backup an Close the other Database
    }
}
