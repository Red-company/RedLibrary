#include <iostream>

#include "../RedLibrary/src/Ipv4.h"

int main() {
    system("clear");

    // We have two ways to define an Ipv4 string.
    // First:
    Red::Ipv4 *IpTest1 = new Red::Ipv4("127", "127.0.0.1");
    // Second:
    Red::Ipv4 IpTest2;

    IpTest2.Set("25", "25.0.0.0"); // The first argument mean the mode of our ip string.
    // It means that the first num can't be more or less than '25' (in this case).
    // We can show ip by Show method.
    std::cout << "IpTest1: " << IpTest1->Show() << std::endl;
    std::cout << "IpTest2: " << IpTest2.Show() << std::endl;

    // We can increment and decriment our ip.
    IpTest1->Next();
    IpTest2.Previous();

    std::cout << std::endl;
    std::cout << "IpTest1 after incrementation: " << IpTest1->Show() << std::endl;
    std::cout << "IpTest2 after decrementation: " << IpTest2.Show() << std::endl;

    // Also we have ip generation function.
    Red::Ipv4 *IpTest3 = new Red::Ipv4;
    IpTest3->Gen();

    std::cout << std::endl;
    std::cout << "IpTest3 after gen func: " << IpTest3->Show() << std::endl;

    delete IpTest1;

    return 0;
}