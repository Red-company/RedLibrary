#include <iostream>

#include "../RedLibrary/FastMath/FastSqrt.h"

int main() {
    system("clear");

    int number1 = 144,
        number2 = 169,
        number3 = 196,
        number4 = 225;

    float result1 = Red::fi_sqrt(number1);
    float result2 = Red::fi_sqrt(number2);
    float result3 = Red::fi_sqrt(number3);
    float result4 = Red::fi_sqrt(number4);

    std::cout << "sqrt 144: " << number1 * result1 << ",\n inversed: " << result1 << std::endl << std::endl;
    std::cout << "sqrt 169: " << number2 * result2 << ",\n inversed: " << result2 << std::endl << std::endl;
    std::cout << "sqrt 225: " << number3 * result3 << ",\n inversed: " << result3 << std::endl << std::endl;
    std::cout << "sqrt 225: " << number4 * result4 << ",\n inversed: " << result4 << std::endl << std::endl;
    std::cout << std::endl;

    return 0;
}
