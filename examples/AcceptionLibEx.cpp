#include <iostream>
#include <thread>

#include "../RedLibrary/AcceptionLib.h" // Rewrite.

int main() {
    Red::AcceptionObj continueask;

    // Base example.
    if (continueask.Request() == true) {
        std::cout << "Received YES" << std::endl;
    } else {
        std::cout << "Received NO"  << std::endl;
    }

    // Custom one.
    if (continueask.Request("So, let's go?") == true) {
        std::cout << "Received YES" << std::endl;
    } else {
        std::cout << "Received NO"  << std::endl;
    }

    return 0;
}
