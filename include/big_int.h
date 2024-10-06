#pragma once
#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include<string>
#include <algorithm>  // For std::all_of
#include <cctype>     // For std::isdigit


class Big_int{
    std::string num;// private string which will hold the given value. in case of negative no num[0]= '-'
     bool is_valid_num(std::string );
    static bool is_valid_number(const std::string& input);  
    public:  
        Big_int(): num("0"){};//default value assigned expected to be 0
        Big_int(int); // if int used
        Big_int(long long int); 
        Big_int(double );
        Big_int(float );
        Big_int(std::string);//will assign the valid input number
       void print();
       // Friend function to overload << operator for output
    friend std::ostream& operator<<(std::ostream& stream, const Big_int& n);
    //input stream
    friend std::istream& operator>>(std::istream& stream, Big_int& n);

   // Friend function for prefix increment
    friend Big_int& operator++(Big_int& n);
   // Friend function for prefix decrement
    friend Big_int& operator--(Big_int& n);

     // Postfix increment operator (with int parameter to differentiate it)
    friend Big_int operator++(Big_int& n, int);
     // Postfix decrement operator (with int parameter to differentiate it)
    friend Big_int operator--(Big_int& n, int);



};


#endif