#include <stdio.h>
#include <math.h>
#include <random>
#include <chrono>

#include "../RedLibrary/2layerDiffieHellman.h"
#include "../RedLibrary/RedTypes.h"

int main() {
    Red::bignum_t P = 1, a1, a2, b1, b2;
    srand(time(0));

    // Generating secrets.
    a1 = rand() % RED_2lDH_RANDOM_A1_KEY_70 + 2; // also there're 100, 140.
    a2 = rand() % RED_2lDH_RANDOM_A1_KEY_70 + 2;

    b1 = rand() % RED_2lDH_RANDOM_A1_KEY_70 + 2;
    b2 = rand() % RED_2lDH_RANDOM_A1_KEY_70 + 2;


    Red::TwoLayerDiffieHellman Alice(&P, &a1, &a2);
    Red::TwoLayerDiffieHellman Bob(RED_2lDH_P_UNLIMITED, &b1, &b2); // same to P = 1;

    std::cout << std::endl;
    std::cout << "The private keys('a1 : a2') for Alice : " << a1 << " : " << a2 << std::endl;
    std::cout << "The private keys('b1 : b2') for Bob   : " << b1 << " : " << b2 << std::endl << std::endl;

    // Generating public keys.
    Red::bignum_t *Pa = Alice.Part1_GetPublicValue();
    Red::bignum_t *Pb = Bob.Part1_GetPublicValue();

    std::cout << "Pa: " << *Pa << std::endl << std::endl;
    std::cout << "Pb: " << *Pb << std::endl << std::endl;

    // Generating a pair of a base num.
    Alice.Part1_GetSymmetricBaseNum(Pb);
    Bob.Part1_GetSymmetricBaseNum(Pa);

    auto start = std::chrono::system_clock::now();

    // Generating a num.
    Red::bignum_t *ValueA = Alice.Part2_GetPublicValue();
    Red::bignum_t *ValueB = Bob.Part2_GetPublicValue();

    // Getting the result pair.
    Red::bignum_t *Sa = Alice.Part2_GetSymmetricSecret(ValueB);
    Red::bignum_t *Sb = Bob.Part2_GetSymmetricSecret(ValueA);

    auto duration = (std::chrono::system_clock::now() - start) * 0.000001;

    std::cout << "Secret key for the Alice is : " << *Sa << std::endl << std::endl << std::endl;
    std::cout << "Secret Key for the Bob is   : " << *Sb << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Time spent: " << duration.count() << " seconds, ~" << 1 / float(duration.count()) << " cycles/sec" << std::endl;

    // How to use one more time the 2lDH object?
    //
    // Like this:
    //
    // Alice.Set(-newP-,-newA1-,-newA2-,-mode-);

    // Freeing up memory.
    delete Pa;
    delete Pb;
    delete ValueA;
    delete ValueB;
    delete Sa;
    delete Sb;

    return 0;
}
