#include<stdio.h>
#include<math.h>

#include "../RedLibrary/DiffieHellman.h"
#include "../RedLibrary/Randomizer.h"
#include "../RedLibrary/RedTypes.h"

int main() {
    Red::uint65536_t P, G, x, a, y, b, ka, kb;

    // Both the persons will be agreed upon the
    // public keys G and P
    P = -1; // A prime number P is taken
    std::cout << "The value of P : " << P << std::endl;

    G = 2; // A primitve root for P, G is taken
    std::cout << "The value of G : " << G << std::endl << std::endl;

    // Generating secrets.
    a = 7000000;//Red::Randomize() % 7000000 + 1; // a (E [1; 7000001]. Warning: Takes a lot of time to calculate.
    b = 90;

    Red::DiffieHellman<Red::uint65536_t> Alice(G, P, a);
    Red::DiffieHellman<Red::uint65536_t> Bob(G, P, b);

    std::cout << "The private key a for Alice : " << a << std::endl;
    std::cout << "The private key b for Bob   : " << b << std::endl << std::endl;

    // Generating public keys.
    x = Alice.GetPublicValue();
    y = Bob.GetPublicValue();

    // Generating key pair.
    ka = Alice.GetSymmetricKey(y);
    kb = Bob.GetSymmetricKey(x);

    std::cout << "Secret key for the Alice is : " << ka << std::endl;
    std::cout << "Secret Key for the Bob is   : " << kb << std::endl;

    return 0;
}
