#include <iostream>

#include "../RedLibrary/FileBuffer.h" // Connecting the lib.

int main() {
    system("clear");

    std::string     bufff; // Defining a string buffer, which we'll use to recieve a string from filebuf.
    Red::FileBuffer fb;    // And defining a filebuffer.

    fb.SetupBuffer("/Users/vladimir/Desktop/testbuf.txt"); // Setting up a filebuf.
    // The buf will save 250 digits per line.
    // Number of lines starts from '1'.
    // The following operation saves string which length is more than 1300 (will be 6 lines).
    fb.AddToBuf("fine/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txttestbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbu/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt/Users/vladimir/Desktop/testbuf.txt");

    // Let's write out our filebuf.
    for (int g = 1; fb.GetStringTo(&bufff); g++) {
        std::cout << std::endl << "str " << g << ": " << bufff << std::endl;
    }

    return 0;
}
