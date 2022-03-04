/**
 * @file    Column.cpp
 * @ingroup RedDataBase
 * @brief   Encapsulation of a Column in a row of the result pointed by the prepared RedDataBase::Statement.
 *
 * Copyright (c) 2020-forever Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "./RedDataBase/Column.h"

#include <sqlite3.h>

#include <iostream>

namespace Red::RedDataBase {
    const int INTEGER   = SQLITE_INTEGER;   ///< REDDATABASE_INTEGER
    const int FLOAT     = SQLITE_FLOAT;     ///< REDDATABASE_FLOAT
    const int TEXT      = SQLITE_TEXT;      ///< REDDATABASE_TEXT
    const int BLOB      = SQLITE_BLOB;      ///< REDDATABASE_BLOB
    const int Null      = SQLITE_NULL;      ///< REDDATABASE_NULL

    // Encapsulation of a Column in a row of the result pointed by the prepared Statement.
    Column::Column(Statement::Ptr& aStmtPtr, int aIndex) noexcept :
        mStmtPtr(aStmtPtr), mIndex(aIndex) {}

    // Return the named assigned to this result column (potentially aliased)
    const char* Column::getName() const noexcept {
        return sqlite3_column_name(mStmtPtr, mIndex);
    }

    #ifdef REDDATABASE_ENABLE_COLUMN_METADATA
    // Return the name of the table column that is the origin of this result column
    const char* Column::getOriginName() const noexcept {
        return sqlite3_column_origin_name(mStmtPtr, mIndex);
    }
    #endif

    /**
     * @brief getInt
     *
     * @return Integer value of the column.
     */
    int Column::getInt() const noexcept {
        return sqlite3_column_int(mStmtPtr, mIndex);
    }

    /**
     * @brief getUInt
     *
     * @return 32bits unsigned integer value of the column (note that SQLite3 does not support unsigned 64bits).
     */
    unsigned Column::getUInt() const noexcept {
        return static_cast<unsigned>(getInt64());
    }

    /**
     * @brief getInt64
     *
     * @return 64bits integer value of the column (note that SQLite3 does not support unsigned 64bits).
     */
    long long Column::getInt64() const noexcept {
        return sqlite3_column_int64(mStmtPtr, mIndex);
    }

    /**
     * @brief getDouble
     *
     * @return Double (64bits float) value of the column.
     */
    double Column::getDouble() const noexcept {
        return sqlite3_column_double(mStmtPtr, mIndex);
    }

    /**
     * @brief Return a pointer to the text value (NULL terminated string) of the column.
     *
     * @warning The value pointed at is only valid while the statement is valid (ie. not finalized),
     *          thus you must copy it before using it beyond its scope (to a std::string for instance).
     *
     * @return Pointer to the text value (NULL terminated string) of the column specified by its index starting at 0.
     */
    const char* Column::getText(const char* apDefaultValue /* = "" */) const noexcept {
        const char* pText = reinterpret_cast<const char*>(sqlite3_column_text(mStmtPtr, mIndex));
        return (pText?pText:apDefaultValue);
    }

    /**
     * @brief Return a pointer to the binary blob value of the column.
     *
     * @warning The value pointed at is only valid while the statement is valid (ie. not finalized),
     *          thus you must copy it before using it beyond its scope (to a std::string for instance).
     *
     * @return Pointer to the text value (NULL terminated string) of the column specified by its index starting at 0.
     */
    const void* Column::getBlob() const noexcept {
        return sqlite3_column_blob(mStmtPtr, mIndex);
    }

    /**
     * @brief Return a std::string for a TEXT or BLOB column.
     *
     * Note this correctly handles strings that contain null bytes.
     *
     * @return String to a TEXT or BLOB column.
     */
    std::string Column::getString() const {
        // Note: using sqlite3_column_blob and not sqlite3_column_text
        // - no need for sqlite3_column_text to add a \0 on the end, as we're getting the bytes length directly
        const char *data = static_cast<const char *>(sqlite3_column_blob(mStmtPtr, mIndex));

        // SQLite docs: "The safest policy is to invoke… sqlite3_column_blob() followed by sqlite3_column_bytes()"
        // Note: std::string is ok to pass nullptr as first arg, if length is 0
        return std::string(data, sqlite3_column_bytes(mStmtPtr, mIndex));
    }

    /**
     * @brief Return the type of the value of the column
     *
     * Return either RedDataBase::INTEGER, RedDataBase::FLOAT, RedDataBase::TEXT, RedDataBase::BLOB, or RedDataBase::Null.
     *
     * @warning After a type conversion (by a call to a getXxx on a Column of a Yyy type),
     *          the value returned by sqlite3_column_type() is undefined.
     *
     * @return Type of the value of the column.
     */
    int Column::getType() const noexcept {
        return sqlite3_column_type(mStmtPtr, mIndex);
    }

    /**
     * @brief Return the number of bytes used by the text (or blob) value of the column
     *
     * @return Number of bytes used by the text value of the column
     *
     * Return either :
     * - size in bytes (not in characters) of the string returned by getText() without the '\0' terminator
     * - size in bytes of the string representation of the numerical value (integer or double)
     * - size in bytes of the binary blob returned by getBlob()
     * - 0 for a NULL value
     */
    int Column::getBytes() const noexcept {
        return sqlite3_column_bytes(mStmtPtr, mIndex);
    }

    // Standard std::ostream inserter
    std::ostream& operator<<(std::ostream& aStream, const Column& aColumn) {
        aStream.write(aColumn.getText(), aColumn.getBytes());
        return aStream;
    }
}
