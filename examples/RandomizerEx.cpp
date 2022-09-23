#include <iostream>

#include "../RedLibrary/Randomizer.h"

int main() {
    // Randomize().

    unsigned long long int *rand1 = Red::Randomize();

    *rand1 = *rand1 % 2000000000 + 1;

    std::cout << "Random num in [1; 2.000.000.000]: " << *rand1 << std::endl << std::endl;

    delete rand1;


    // Randomize_custom().

    unsigned long long int len = 17;

    Red::bignum_t *rand2 = Red::Randomizer_custom(&len);

    std::cout << "Random num of len=17: " << *rand2 << std::endl;

    delete rand2;
}
