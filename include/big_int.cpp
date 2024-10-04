
#include "big_int.h"
#include<iostream>
#include<sstream>
#include<iomanip>


//helper function to handle the floating_point values
template <typename T>
std::string convert_floating_point(T num) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6) << num;  // Set precision (6 decimal places)
    std::string result = oss.str();

    // Remove trailing zeros
    result.erase(result.find_last_not_of('0') + 1, std::string::npos);

    // Remove the decimal point if it's at the end
    if (result.back() == '.') {
        result.pop_back();
    }

    return result;
}


Big_int::Big_int(std::string input){
    if(is_valid_num(input)){
        this->num= input;
    }else  
        throw std::runtime_error("Invalid number given");
    
    return;
}

Big_int::Big_int(int num){
    this->num= std::to_string(num);
    return;
}

Big_int::Big_int(long long int num){
    this->num= std::to_string(num);
    return;
}

Big_int::Big_int(float num){
    this->num= convert_floating_point(num);
}

Big_int::Big_int(double num){
    this->num= convert_floating_point(num);
}


void Big_int::print(){
    std::cout << num;
}

bool Big_int::is_valid_num(std::string str){

    if (str.empty()) return false;
    size_t start = (str[0] == '-') ? 1 : 0;  // Handle negative numbers
    bool has_dot = false;
    
    for (size_t i = start; i < str.size(); ++i) {
        if (str[i] == '.') {
            if (has_dot) return false;  // More than one dot is invalid
            has_dot = true;
        } else if (!(str[i] >='0' && str[i]<='9')) {
            return false;  // Non-digit characters are invalid
        }
    }

    return true;
     

    /*
        We need to validate the number. number should not have any character other than digits and decimal point.

     */

}


bool Big_int::is_valid_number(const std::string& input) {
    if (input.empty()) return false;

    size_t start = 0;
    bool has_dot = false;

    // Check for negative sign
    if (input[0] == '-') {
        if (input.length() == 1) return false;  // Invalid: just "-"
        start = 1;
    }

    // Check the rest of the string
    for (size_t i = start; i < input.size(); ++i) {
        if (input[i] == '.') {
            if (has_dot) return false;  // More than one dot is invalid
            has_dot = true;
        } else if (!isdigit(input[i])) {
            return false;  // Non-digit character found
        }
    }

    return true;  // Valid number
}


// Overloaded >> operator for Big_int
std::istream& operator>>(std::istream& stream, Big_int& n) {
    std::string input;
    stream >> input;

    // Validate the input string
    if (Big_int::is_valid_number(input)) {
        n.num = input;
    } else {
        stream.setstate(std::ios::failbit);  // Set failbit if invalid
        throw std::invalid_argument("Invalid number input");
    }

    return stream;
}