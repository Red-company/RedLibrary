#include <boost/test/unit_test.hpp>

#include <string>

#include "RedEncryptionAlgorithms/Va1.h"


BOOST_AUTO_TEST_SUITE(Va1_tests)

BOOST_AUTO_TEST_CASE(Va_16) {
    const std::string Str16 = "1234567890abcdef";

    std::string *resE = Red::Va1Encode(&Str16);
    std::string *resD = Red::Va1Decode(resE);

    BOOST_REQUIRE(Str16 == *resD);

    delete resE;
    delete resD;
}
#include <iostream>
BOOST_AUTO_TEST_CASE(Va_all) {
    const std::string Str = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+1234567890-=[]{};:| \' \" \\ /.,<>`~";
    const std::string R   = "22112302031504241401162105072506131900172008101209188978906970827191816883887274567380866784877577797685262730323134293328353637626061635965586466574139484947504644455394535253935392424340385455";

    std::string *resE = Red::Va1Encode(&Str);
    std::cout << *resE << std::endl;
    BOOST_REQUIRE(R == *resE);

    delete resE;
}

BOOST_AUTO_TEST_SUITE_END()
