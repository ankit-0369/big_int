#include "../include/big_int.h"
#include <iostream>

int main() {
    Big_int number1;
    Big_int number2;
    Big_int number3;

    try {
    std::cout << "Enter a valid number1: ";
        std::cin >> number1;  // Input a number
    std::cout << "Enter a valid number2: ";
        std::cin >> number2;  // Input a number
    std::cout << "Enter a valid number3: ";
        std::cin >> number3;  // Input a number
      // Print the number if valid
        // std::cout<<--number<<"\n";
        std::cout<<number1-number2<<"\n";

        // std::cout<<++number<<"\n";
        // std::cout<<number--<<"\n";
        // std::cout<<number<<"\n";
            // Print the number if valid
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;  // Handle invalid input
    }
    

    return 0;
}
