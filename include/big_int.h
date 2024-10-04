#pragma once
#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include<string>

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
       friend std::ostream& operator<<(std::ostream& stream, const Big_int& n){
            stream << n.num;
            return stream;
       }
    //input stream
   friend std::istream& operator>>(std::istream& stream, Big_int& n);


};


#endif