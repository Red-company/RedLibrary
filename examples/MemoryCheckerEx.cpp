#include <iostream>

// Connecting lib.
#include "../RedLibrary/MemoryChecker.h"

int main(){
    // Ram statistics.

    std::cout << "Total:  " << Red::RAM::GetTotalMemory() << " bytes." << std::endl;
    std::cout << "Used:   " << Red::RAM::GetMemoryUsage() << " bytes." << std::endl;
    std::cout << "Free:   " << Red::RAM::GetFreeMemory()  << " bytes." << std::endl;
    std::cout << std::endl;

    // Rom statistics.

    std::string Path = "/Users/vladimir/Desktop/example.db3";

    std::cout << "Total:  " << Red::ROM::GetTotalMemory(Path)      << " bytes." << std::endl;
    std::cout << "Used:   " << Red::ROM::GetMemoryUsage(Path)      << " bytes." << std::endl;
    std::cout << "Used_r: " << Red::ROM::GetMemoryUsage_root(Path) << " bytes." << std::endl;
    std::cout << "Free:   " << Red::ROM::GetFreeMemory(Path)       << " bytes." << std::endl;
    std::cout << "Free_r: " << Red::ROM::GetFreeMemory_root(Path)  << " bytes." << std::endl;

    return 0;
}
