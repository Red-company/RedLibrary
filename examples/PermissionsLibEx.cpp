#include<iostream>

// Connecting lib.
#include "../RedLibrary/PermissionsLib.h"

int main() {
    std::cout << "Root permission: " << Red::PermissionsLib::CheckRootPermissions() << std::endl;

    return 0;
}
