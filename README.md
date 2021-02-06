![plot](./RedLibrary_logo.png)

# RedLibrary [![](https://img.shields.io/apm/l/vim-mode)](https://github.com/Red-company/RES_Implementation/blob/main/LICENSE.md) [![](https://img.shields.io/github/repo-size/Red-company/RedLibrary)](https://github.com/Red-company/RedLibrary)

## What is it?

This is a library which uses by Red projects.

## How to use it?

All examples are in "examples" folder.

**Notes:**
  * Made in C++17
  * Requires these libraries:
    * Boost
    * Openssl
    * Fmt
    * Sqlite3
    * Unicode(icu4c)
    * Gsasl

## What does RedLibrary consist of?

* RedLibrary
  * EncryptionAlgorithms
    * _private
      * AesDeclarations.h
    * AesCBC128.h
    * AesCBC128.cpp
    * AesCBC192.h
    * AesCBC192.cpp
    * AesCBC256.h
    * AesCBC256.cpp
    * AesECB128.h
    * AesECB128.cpp
    * AesECB192.h
    * AesECB192.cpp
    * AesECB256.h
    * AesECB256.cpp
  * HashFunctions
    * Sha256.h
    * Sha256.cpp
  * RedConfig
    * Exceptions.h
  * RedDataBase
    * Assertion.h
    * Backup.h
    * Backup.cpp
    * Column.h
    * Column.cpp
    * Database.h
    * Database.cpp
    * Exception.h
    * Exception.cpp
    * ExecuteMany.h
    * Statement.h
    * Statement.cpp
    * Transaction.h
    * Transaction.cpp
    * Utils.h
    * VariadicBind.h
  * RedEncryptionAlgorithms
    * _private
      * ResDeclarations.h
    * ResCBC1024.h
    * ResCBC1024.cpp
    * ResCBC1536.h
    * ResCBC1536.cpp
    * ResCBC512.h
    * ResCBC512.cpp
    * ResECB1024.h
    * ResECB1024.cpp
    * ResECB1536.h
    * ResECB1536.cpp
    * ResECB512.h
    * ResECB512.cpp
    * Va1.h
    * Va1.cpp
  * ExecutionTime.h
  * FileBuffer.h
  * Hex.h
  * InsensitiveMap.h
  * Ipv4.h
  * MemoryChecker.h
  * PassGenerator.h
  * PermissionsLib.h
  * ProgressBar.h
  * RedConfig.h
  * RedConfig.cpp
  * RedDataBase.h
  
**Notes:**
 * If you want to route result of AES / RES encryption to `std::cout`, you should convert string to hexadecimal system, in other way you will get bad output!
  * **Convertion functions are in Hex.h.**
 * In AES and RES there are no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

All material in this repository is in the public domain.
