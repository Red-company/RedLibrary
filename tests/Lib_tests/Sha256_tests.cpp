#include <boost/test/auto_unit_test.hpp>

#include <string>

#include "HashFunctions/Sha256.h"


BOOST_AUTO_TEST_SUITE(Sha256_tests)

BOOST_AUTO_TEST_CASE(Sha256_1) {
    std::string in = "0123456789abcdef";

    std::string res = "9f9f5111f7b27a781f1f1ddde5ebc2dd2b796bfc7365c9c28b548e564176929f";

    std::string *out = Red::Sha256Hash(&in);

    BOOST_REQUIRE(*out == res);

    delete out;
}

BOOST_AUTO_TEST_CASE(Sha256_2) {
    std::string in = "0000000000000000";

    std::string res = "fcdb4b423f4e5283afa249d762ef6aef150e91fccd810d43e5e719d14512dec7";

    std::string *out = Red::Sha256Hash(&in);

    BOOST_REQUIRE(*out == res);

    delete out;
}

BOOST_AUTO_TEST_CASE(Sha256_3) {
    std::string in = "ajroeicutndjaurt";

    std::string res = "e367726eb5408296f17926687d28ae148611025becbdc2e0d7834b7b6e96ef4d";

    std::string *out = Red::Sha256Hash(&in);

    BOOST_REQUIRE(*out == res);

    delete out;
}

BOOST_AUTO_TEST_CASE(Sha256_4) {
    std::string in = "17c8a93bdy73;a'c";

    std::string res = "13047259f17b5259d79214c86197e47cb2d58bf3ccefdbc22930bfa0571700bf";

    std::string *out = Red::Sha256Hash(&in);

    BOOST_REQUIRE(*out == res);

    delete out;
}

BOOST_AUTO_TEST_SUITE_END()
