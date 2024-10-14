#include "../include/big_int.h"
#include <iostream>

int main()
{
    Big_int number1;
    Big_int number2;
    Big_int number3;

    // try
    // {
    //     std::cout << "Enter a valid number1: ";
    //     std::cin >> number1; // Input a number
    //     std::cout << "Enter a valid number2: ";
    //     std::cin >> number2; // Input a number
    //     std::cout << "Enter a valid number3: ";
    //     std::cin >> number3; // Input a number
    //                          // Print the number if valid
    //     // std::cout<<--number<<"\n";
    //     std::cout << number1 - number2 << "\n";

    //     // std::cout<<++number<<"\n";
    //     // std::cout<<number--<<"\n";
    //     // std::cout<<number<<"\n";
    //     // Print the number if valid
    // }
    // catch (const std::invalid_argument &e)
    // {
    //     std::cerr << e.what() << std::endl; // Handle invalid input
    // }

    /*
        ============================================================
        =================condtional operators check=================
        ============================================================
    */

    try
    {
        // Big_int num1;
        // Big_int num2;
        // std::cin >> num1 >> num2;
        long long num2= 100;
         Big_int num1("100");
        std::cout<<num1<<"\n";
        bool res = (num1 >= num2);
        std::cout << " greater than comparison result :: " << res << std::endl;
        bool res1 = (num1 <= num2);
        std::cout << " less than comparison result :: " << res1 << std::endl;

        Big_int n1("1234567898");
        Big_int n2("1234567898");
        std::cout<<"equal comparison result :: "<< (n1 == n2)<<std::endl;
        std::cout<<"Not Equal comparison result :: "<< (n1 != n2)<<std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
