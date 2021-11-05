#include <iostream>

#include "../RedLibrary/Randomizer.h"

int main() {
    std::cout << "Random num in [1; 2.000.000.000]: " << Red::Randomize() % 2000000000 + 1 << std::endl;
}