#include <boost/test/auto_unit_test.hpp>

#include <string>

#include "EncryptionAlgorithms/AesCBC128.h"
#include "EncryptionAlgorithms/AesCBC192.h"
#include "EncryptionAlgorithms/AesCBC256.h"
#include "EncryptionAlgorithms/AesECB128.h"
#include "EncryptionAlgorithms/AesECB192.h"
#include "EncryptionAlgorithms/AesECB256.h"
#include "Hex.h"


BOOST_AUTO_TEST_SUITE(AES_tests)

//
// AES_CBC_128.
//

// 16.

BOOST_AUTO_TEST_CASE(AES_CBC_128_16_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "0b9b15da4b44a0f5151dcfc4c01f35d5";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_16_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "0b9b15da4b44a0f5151dcfc4c01f35d5";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_16_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 32.

BOOST_AUTO_TEST_CASE(AES_CBC_128_32_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "0b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d5";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_32_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "0b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d5";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_32_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 64.

BOOST_AUTO_TEST_CASE(AES_CBC_128_64_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "0b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d5";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_64_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "0b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d5";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_64_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 128.

BOOST_AUTO_TEST_CASE(AES_CBC_128_128_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "0b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d5";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_128_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "0b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d50b9b15da4b44a0f5151dcfc4c01f35d5";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_128_128_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC128(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC128(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


//
// AES_CBC_192.
//

// 16.

BOOST_AUTO_TEST_CASE(AES_CBC_192_16_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "601cf8398228b97631fad8b1d005e705";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_16_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "601cf8398228b97631fad8b1d005e705";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_16_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 32.

BOOST_AUTO_TEST_CASE(AES_CBC_192_32_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_32_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_32_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 64.

BOOST_AUTO_TEST_CASE(AES_CBC_192_64_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_64_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_64_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 128.

BOOST_AUTO_TEST_CASE(AES_CBC_192_128_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_128_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705601cf8398228b97631fad8b1d005e705";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_192_128_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC192(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC192(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


//
// AES_CBC_256.
//

// 16.

BOOST_AUTO_TEST_CASE(AES_CBC_256_16_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "7dbd88272fb25937692a3b8100474175";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_16_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "7dbd88272fb25937692a3b8100474175";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_16_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 32.

BOOST_AUTO_TEST_CASE(AES_CBC_256_32_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "7dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b8100474175";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_32_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "7dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b8100474175";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_32_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 64.

BOOST_AUTO_TEST_CASE(AES_CBC_256_64_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "7dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b8100474175";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_64_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "7dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b8100474175";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_64_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 128.

BOOST_AUTO_TEST_CASE(AES_CBC_256_128_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string res = "7dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b8100474175";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_128_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "7dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b81004741757dbd88272fb25937692a3b8100474175";
    std::string iv  = "0123456789abcdef";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_CBC_256_128_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


//
// AES_ECB_128.
//

// 16.

BOOST_AUTO_TEST_CASE(AES_ECB_128_16_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef";

    std::string res = "72727e881edcfd0100a718687909b565";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_16_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "72727e881edcfd0100a718687909b565";

    std::string res = "0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_16_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 32.

BOOST_AUTO_TEST_CASE(AES_ECB_128_32_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";

    std::string res = "72727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b565";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_32_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "72727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b565";

    std::string res = "0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_32_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 64.

BOOST_AUTO_TEST_CASE(AES_ECB_128_64_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string res = "72727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b565";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_64_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "72727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b565";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_64_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 128.

BOOST_AUTO_TEST_CASE(AES_ECB_128_128_enc) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string res = "72727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b565";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_128_dec) {
    std::string key = "0123456789abcdef";
    std::string in  = "72727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b56572727e881edcfd0100a718687909b565";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_128_128_2sides) {
    std::string key = "0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB128(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB128(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


//
// AES_ECB_192.
//

// 16.

BOOST_AUTO_TEST_CASE(AES_ECB_192_16_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef";

    std::string res = "da6c0e29c6927225e61f590db4ea78f7";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_16_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "da6c0e29c6927225e61f590db4ea78f7";

    std::string res = "0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_16_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 32.

BOOST_AUTO_TEST_CASE(AES_ECB_192_32_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef";

    std::string res = "da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_32_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7";

    std::string res = "0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_32_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 64.

BOOST_AUTO_TEST_CASE(AES_ECB_192_64_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string res = "da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_64_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_64_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 128.

BOOST_AUTO_TEST_CASE(AES_ECB_192_128_enc) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string res = "da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_128_dec) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7da6c0e29c6927225e61f590db4ea78f7";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_192_128_2sides) {
    std::string key = "0123456789abcdef01234567";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB192(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB192(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


//
// AES_ECB_256.
//

// 16.

BOOST_AUTO_TEST_CASE(AES_ECB_256_16_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef";

    std::string res = "f83c9a60dc0cdb98219f79d6d5db1635";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_16_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "f83c9a60dc0cdb98219f79d6d5db1635";

    std::string res = "0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_16_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 32.

BOOST_AUTO_TEST_CASE(AES_ECB_256_32_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";

    std::string res = "f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_32_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635";

    std::string res = "0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_32_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 64.

BOOST_AUTO_TEST_CASE(AES_ECB_256_64_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string res = "f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_64_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_64_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}


// 128.

BOOST_AUTO_TEST_CASE(AES_ECB_256_128_enc) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string res = "f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    BOOST_REQUIRE(*EncryptedHex == res);

    delete EncryptedStr;
    delete EncryptedHex;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_128_dec) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635f83c9a60dc0cdb98219f79d6d5db1635";

    std::string res = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *ForDecrypt = Red::GetStrArray(in);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == res);

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_CASE(AES_ECB_256_128_2sides) {
    std::string key = "0123456789abcdef0123456789abcdef";
    std::string in  = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    BOOST_REQUIRE(*Decrypted == in);

    delete EncryptedStr;
    delete EncryptedHex;

    delete ForDecrypt;
    delete Decrypted;
}

BOOST_AUTO_TEST_SUITE_END()
