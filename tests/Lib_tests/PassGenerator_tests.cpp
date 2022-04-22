#include <boost/test/unit_test.hpp>

#include <string>

#include "PassGenerator.h"


BOOST_AUTO_TEST_SUITE(PassGenerator_tests)

//
// Only nums.
//

BOOST_AUTO_TEST_CASE(Only_nums_8) {
    unsigned short int len = 8;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_ONLY_NUMS);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Only_nums_16) {
    unsigned short int len = 16;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_ONLY_NUMS);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Only_nums_32) {
    unsigned short int len = 32;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_ONLY_NUMS);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Only_nums_64) {
    unsigned short int len = 64;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_ONLY_NUMS);

    BOOST_REQUIRE(res.length() == len);
}


//
// Nums and Letters.
//

BOOST_AUTO_TEST_CASE(Nums_and_letters_8) {
    unsigned short int len = 8;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_NUMS_AND_LETTERS);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Nums_and_letters_16) {
    unsigned short int len = 16;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_NUMS_AND_LETTERS);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Nums_and_letters_32) {
    unsigned short int len = 32;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_NUMS_AND_LETTERS);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Nums_and_letters_64) {
    unsigned short int len = 64;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_NUMS_AND_LETTERS);

    BOOST_REQUIRE(res.length() == len);
}


//
// Va1 Mode.
//

BOOST_AUTO_TEST_CASE(Va1_mode_8) {
    unsigned short int len = 8;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_Va1_MODE);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Va1_mode_16) {
    unsigned short int len = 16;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_Va1_MODE);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Va1_mode_32) {
    unsigned short int len = 32;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_Va1_MODE);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_CASE(Va1_mode_64) {
    unsigned short int len = 64;

    std::string res = Red::GeneratePassword(len, REDPASSGENERATOR_Va1_MODE);

    BOOST_REQUIRE(res.length() == len);
}

BOOST_AUTO_TEST_SUITE_END()
