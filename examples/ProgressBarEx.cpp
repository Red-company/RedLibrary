#include <iostream>
#include <thread>

#include "../RedLibrary/ProgressBar.h" // Rewrite.

int main() {
    Red::ProgressBar pb;

    for (int e = 0; e <= 100; e++) {
        pb.Show();
        pb.Increment();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    system("clear");
    return 0;
}