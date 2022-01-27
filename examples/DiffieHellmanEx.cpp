#include <stdio.h>
#include <math.h>
#include <random>
#include <chrono>

#include "DiffieHellman/DiffieHellman.h"
#include "DiffieHellman/RedTypes.h"

int main() {
    Red::uint65536_t P, G, a, b;
    srand(time(0));

    // Both the persons will be agreed upon the
    // public keys G and P
    P = -1; // A prime number P is taken
    std::cout << "The value of P : " << P << std::endl << std::endl;

    G = 2; // A primitve root for P, G is taken
    std::cout << "The value of G : " << G << std::endl << std::endl;

    // Generating secrets.
    a = rand() % 10000 + 2; //Red::Randomize() % 7000000 + 1; //Randomizer is in RedLibrary, a (E [1; 7000001]. Warning: Takes a lot of time to calculate.
    b = 204;

    auto start = std::chrono::system_clock::now();

    Red::DiffieHellman<Red::uint65536_t> Alice(&G, &P, &a);
    Red::DiffieHellman<Red::uint65536_t> Bob(&G, &P, &b);

    std::cout << "The private key a for Alice : " << a << std::endl;
    std::cout << "The private key b for Bob   : " << b << std::endl << std::endl;

    // Generating public keys.
    Red::uint65536_t *x = Alice.GetPublicValue();
    Red::uint65536_t *y = Bob.GetPublicValue();

    // Generating key pair.
    Red::uint65536_t *ka = Alice.GetSymmetricKey(y);
    Red::uint65536_t *kb = Bob.GetSymmetricKey(x);

    std::cout << "Secret key for the Alice is : " << *ka << std::endl << std::endl;
    std::cout << "Secret Key for the Bob is   : " << *kb << std::endl << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                                (std::chrono::system_clock::now() - start);

    std::cout << "Time: " << std::to_string(duration.count()) << std::endl << std::endl;

    // How to use one more time the DH object?
    //
    // Like this:
    //
    // Alice.Set(-newG-,-newP-,-newA-);

    // Freeing up memory.
    delete x;
    delete y;
    delete ka;
    delete kb;

    return 0;
}
