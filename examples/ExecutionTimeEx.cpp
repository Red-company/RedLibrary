#include <iostream>
#include <unistd.h>
#include <chrono>

#include "../RedLibrary/ExecutionTime.h"

void g() {
    sleep(2);
}

int main() {
    std::cout << "Execution time is " << Red::Measure<std::chrono::milliseconds>::ExecutionTime(g) << "ms." << std::endl;
    return 0;
}
