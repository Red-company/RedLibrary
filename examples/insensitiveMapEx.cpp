#include <iostream>
#include <string>

#include "../RedLibrary/InsensitiveMap.h"

int main() {
    Red::InsensitiveMap<std::string, std::string> im;

    im.insert(std::make_pair<std::string, std::string>("OnE", "1234"));

    // !!! Warning !!!
    // Insensitive is only in functions, uses '()' operator.
    std::cout << "Key: 'one': '"        << (im.find("oNe") != im.end()) << "'." << std::endl;
    std::cout << "Key: 'one', value: '" << im.at("one")                 << "'." << std::endl;

    return 0;
}
