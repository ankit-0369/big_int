#include "../include/big_int.h"
#include <iostream>

int main() {
    Big_int number;

    std::cout << "Enter a valid number: ";
    try {
        std::cin >> number;  // Input a number
      // Print the number if valid
        // std::cout<<--number<<"\n";
        std::cout<<--number<<"\n";
        // std::cout<<++number<<"\n";
        // std::cout<<number--<<"\n";
        std::cout<<number<<"\n";
            // Print the number if valid
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;  // Handle invalid input
    }
    

    return 0;
}
