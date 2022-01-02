![plot](./RedLibrary_logo.png)

# 📚 RedLibrary (مكتبة ريد) [![](https://img.shields.io/apm/l/vim-mode)](https://github.com/Red-company/RES_Implementation/blob/main/LICENSE.md) [![](https://img.shields.io/github/repo-size/Red-company/RedLibrary)](https://github.com/Red-company/RedLibrary) ![](https://img.shields.io/github/stars/Red-company/RedLibrary?style=social)

## What is it?

[--Documentation--](https://red-company.github.io/RedLibrary/)

This is a library which uses by _Red_ projects. It consists of small libraries which are helpful in big projects. Each of these libraries was tested hard and if you see them in this repository, that means that they're reliable.

## How to use it?

These libraries are _'ready to work'_, all you need is just write a code. All examples are in _"examples"_ folder.

##
**Notes:**
  * Made in C++17
  * Requires these libraries:
    * Boost
    * Openssl
    * Fmt
    * Sqlite3
    * Unicode(icu4c)
    * Gsasl
  
##
**Notes 2(About AES and RES):**
 * If you want to route result of _AES_ / _RES_ encryption to _`std::cout`_, you should convert string to hexadecimal system, in other way you will get bad output!
 * Convertion functions are in _Hex.h_.
 * In _AES_ and _RES_ there are no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

##
**Notes 3(About DiffieHellman):**
 * _P_ number (_prime one_) works stable with 19729 characters long (From _'RedTypes.h'_: _'Red::uint65536_t'_).
 * Example of usage is in _'examples'_ folder. It is a good idea to read how diffiehellman works.
 * Needs to understand that the time of calculation rises as the secret key value rises.
 * Tested with _Asecret_=7000000 and _Bsecret_=90, but takes a lot of time to calculate.
 * _Secret key_ is restricted by uint max size in power function(function from boost is used there).

##
**Notes 4(About Randomizer):**
 * Max return value is _'ull' int_.

##
**Notes 5(about Va1):**
 * Original repository is [_here_](https://github.com/vladimirrogozin/Va1).

##
**Notes 6(about Sha256):**
 * Original repository is [_here_](https://github.com/vladimirrogozin/Sha256).

##
**Notes 7(about FastSqrt):**
 * Uses inside _long int_ type.
 * Original repository is [_here_](https://github.com/vladimirrogozin/Fast-sqrt).

##
All material in this repository is in the public domain.
