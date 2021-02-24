#include<stdio.h>
#include<math.h>

#include "../RedLibrary/DiffieHellman.h"

int main()
{
    unsigned long long int P, G, x, a, y, b, ka, kb;

    // Both the persons will be agreed upon the
    // public keys G and P
    P = 3231700607131100791; // A prime number P is taken
    printf("The value of P : %lld\n", P);

    G = 2; // A primitve root for P, G is taken
    printf("The value of G : %lld\n\n", G);

    // Random size.
    unsigned long long int s = 10;

    // Generating secrets.
    a = Red::DiffieHellman::GenerateSecret(s);
    b = 9;

    Red::DiffieHellman Alice(G, P, a);
    Red::DiffieHellman Bob(G, P, b);

    printf("The private key a for Alice : %lld\n", a);
    printf("The private key b for Bob : %lld\n\n", b);

    // Generating public keys.
    x = Alice.GetPublicValue();
    y = Bob.GetPublicValue();

    // Generating key pair.
    ka = Alice.GetSymmetricKey(y);
    kb = Bob.GetSymmetricKey(x);

    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);

    return 0;
}