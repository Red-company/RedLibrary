#include <iostream>
#include <stdio.h>
#include <math.h>

#include "../RedLibrary/DiffieHellman.h"

#include "../RedLibrary/RedTypes.h"

int main() {
    Red::uint8192_t P, G, x, a, y, b, ka, kb;

    // Both the persons will be agreed upon the
    // public keys G and P
    P = -1; // A prime number P is taken
    std::cout << "The value of P : " << P << std::endl;

    G = 3; // A primitve root for P, G is taken
    std::cout << "The value of G : " << G << std::endl << std::endl;

    // Random size.
    Red::uint8192_t s = 16;

    // Generating secrets.
    a = Red::DiffieHellman::GenerateSecret(s);
    b = 90;

    Red::DiffieHellman Alice(G, P, a);
    Red::DiffieHellman Bob(G, P, b);

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
