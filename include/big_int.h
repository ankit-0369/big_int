#pragma once
#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <string>
#include <algorithm> // For std::all_of
#include <cctype>    // For std::isdigit

class Big_int
{
    std::string num; // private string which will hold the given value. in case of negative no num[0]= '-'

    // functions for internal use of the class----

    bool is_valid_num(std::string);
    static bool is_valid_number(const std::string &input);

    static bool is_strictly_maximum(const std::string, const std::string);
    static bool is_loosely_maximum(const std::string, const std::string);
    
    static bool is_strictly_minimum(const std::string, const std::string);
    static bool is_loosely_minimum(const std::string, const std::string);

    static bool is_equal(const std::string, const std::string);
   


public:
    Big_int() : num("0") {}; // default value assigned expected to be 0
    Big_int(int);            // if int used
    Big_int(long long int);
    Big_int(double);
    Big_int(float);
    Big_int(std::string); // will assign the valid input number
    void print();
    static Big_int to_big_int(const auto &value)
    {
        return Big_int(std::to_string(value));
    }

    friend std::ostream &operator<<(std::ostream &stream, const Big_int &n); // Friend function to overload << operator for output
    friend std::istream &operator>>(std::istream &stream, Big_int &n);       // input stream
    friend Big_int &operator++(Big_int &n);                                  // Friend function for prefix increment
    friend Big_int &operator--(Big_int &n);                                  // Friend function for prefix decrement
    friend Big_int operator++(Big_int &n, int);                              // Postfix increment operator (with int parameter to differentiate it)
    friend Big_int operator--(Big_int &n, int);                              // Postfix decrement operator (with int parameter to differentiate it)

    /*
        ========================================================================
        -----------------------------Arithmetic operators------------------------
        =========================================================================

    */
    friend Big_int operator+(const Big_int &n1, const Big_int &n2); // Operator for Sum of two BigInt
    friend Big_int operator-(const Big_int &n1, const Big_int &n2); // Operator for  difference of two BigInt

    /*
        ==================================================================================
       --------------------------------comparison operators-------------------------------
        ==================================================================================
    */
    
    template <typename T>
    friend bool operator>(const T &n1, const Big_int &n2){
        Big_int bn1 = to_big_int(n1);
        return is_strictly_maximum(bn1.num, n2.num);
    }

    friend bool operator>(const Big_int &n1, const Big_int &n2){
        return is_strictly_maximum(n1.num, n2.num);
    }

    template <typename T>
    friend bool operator>=(const T &n1, const Big_int &n2){
        Big_int bn1 = to_big_int(n1);
        return is_loosely_maximum(bn1.num, n2.num);
    }

    friend bool operator>=(const Big_int &n1, const Big_int &n2){
        return is_loosely_maximum(n1.num, n2.num);
    }

    template <typename T>
    friend bool operator<(const T &n1, const Big_int &n2){
        Big_int bn1 = to_big_int(n1);
        return is_strictly_minimum(bn1.num, n2.num);
    }

    friend bool operator<(const Big_int &n1, const Big_int &n2){
        return is_strictly_minimum(n1.num, n2.num);
    }

    template <typename T>
    friend bool operator<=(const T &n1, const Big_int &n2){
        Big_int bn1 = to_big_int(n1);
        return is_loosely_minimum(bn1.num, n2.num);
    }

    friend bool operator<=(const Big_int &n1, const Big_int &n2){
        return is_loosely_minimum(n1.num, n2.num);
    }

    template <typename T>
    friend bool operator==(const T &n1, const Big_int &n2){
        Big_int bn1= to_big_int(n1);
        return is_equal(bn1.num, n2.num);
    }

    friend bool operator==(const Big_int &n1, const Big_int &n2){
        return is_equal(n1.num, n2.num);
    }

    template <typename T>
    friend bool operator!=(const T &n1, const Big_int &n2){
       return !(n1 == n2);
    }

    friend bool operator!=(const Big_int &n1, const Big_int &n2){
        return !(n1 == n2);
    }



};

#endif