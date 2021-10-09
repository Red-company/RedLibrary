#include <iostream>
#include <thread>

#include "../RedLibrary/AcceptionLib.h" // Rewrite.

int main() {
    Red::AcceptionObj continueask;

    if (continueask.Request("go?") == true) {
        std::cout << "Received YES" << std::endl;
    } else {
        std::cout << "Received NO"  << std::endl;
    }

    return 0;
}
