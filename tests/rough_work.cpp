#include "bigint.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        BigInt a("12");
        std::cout<<a.to_string()<<std::endl;

        BigInt b("-0");
        std::cout<<b.to_string();
        std::cout << "created fine\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "caught: " << e.what() << "\n";
    }
    std::cout << "program continues\n";
}