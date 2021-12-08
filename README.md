![plot](./RedLibrary_logo.png)

# RedLibrary (مكتبة ريد) [![](https://img.shields.io/apm/l/vim-mode)](https://github.com/Red-company/RES_Implementation/blob/main/LICENSE.md) [![](https://img.shields.io/github/repo-size/Red-company/RedLibrary)](https://github.com/Red-company/RedLibrary) ![](https://img.shields.io/github/stars/Red-company/RedLibrary?style=social)

## What is it?

[--Documentation--](https://red-company.github.io/RedLibrary/)

This is a library which uses by Red projects. It consists of small libraries which are helpful in big projects. Each of these libraries was tested hard and if you see them in this repository, that means that they're reliable.

## How to use it?

These libraries are 'ready to work', all you need is just write a code. All examples are in "examples" folder.

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
 * If you want to route result of AES / RES encryption to `std::cout`, you should convert string to hexadecimal system, in other way you will get bad output!
 * Convertion functions are in Hex.h.
 * In AES and RES there are no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

##
**Notes 3(About DiffieHellman):**
 * P number (prime one) works stable with 19729 characters long (From 'RedTypes.h': 'Red::uint65536_t').
 * Example of usage is in 'examples' folder. It is a good idea to read how diffiehellman works.
 * Needs to understand that the time of calculation rises as the secret key value rises.
 * Tested with Asecret=7000000 and Bsecret=90, but takes a lot of time to calculate.
 * Secret key is restricted by uint max size in power function(function from boost is used there).

##
**Notes 4(About Randomizer):**
 * Max return value is 'ull' int.

##
All material in this repository is in the public domain.
