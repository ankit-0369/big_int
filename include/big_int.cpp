
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


// Overload the << operator for output
std::ostream& operator<<(std::ostream& stream, const Big_int& n) {
    stream << n.num;  // Output the string representation of the number
    return stream;
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

// Friend function for prefix increment (++n)
Big_int& operator++(Big_int& n) {
    int carry=1;  // Start with carry = 1 (because we are adding 1)
    if(n.num[0]=='-'){
        n.num.erase(0, 1);
        --n;
      if(n.num.size()==1 && n.num[0]=='0')return n;
        n.num='-' + n.num;
        return n;
    }

      
    
    for(int i=n.num.size()-1;i>=0;--i){
        int digit = n.num[i] - '0';
        int sum =digit + carry;
        n.num[i]=(sum%10)+'0';
        carry=sum/10;
    }
    if(carry==1)n.num='1'+ n.num;


    return n;


}

Big_int& operator--(Big_int& n) {
    int borrow=1;  // Start with carry = 1 (because we are adding 1)
    if(n.num[0]=='-'){
        n.num.erase(0, 1);
        ++n;
        if(n.num.size()==1 && n.num[0]=='0')return n;
       n.num='-' + n.num;
        return n;
    }
    
    if(n.num.size()==1 && n.num[0]=='0'){
        n.num = "-1";
        return n;
    }
    // Start from the last digit and process the string from right to left
    for (int i = n.num.size() - 1; i >= 0; i--) {
        if (n.num[i] > '0') {
            n.num[i]--; // Simply subtract 1 from the current digit
            break;
        } else {
            // If the current digit is '0', we need to borrow from the previous digit
            n.num[i] = '9';
        }
    }

    // If the first digit becomes '0', we need to remove it (e.g., 1000 -> 999)
    if (n.num[0] == '0' && n.num.size() > 1) {
        n.num.erase(0, 1);
    }

    return n;

}



Big_int operator++(Big_int& n, int) {
    Big_int temp = n;  // Save the current value

    // Increment 4the number (you can reuse the logic from prefix increment)
    ++n;  // Call the prefix increment to modify n

    return temp;  // Return the original value
}


Big_int operator--(Big_int& n, int) {
    Big_int temp = n;  // Save the current value

    // Increment the number (you can reuse the logic from prefix increment)
    --n;  // Call the prefix increment to modify n

    return temp;  // Return the original value
}


// Operator for  addition
      Big_int operator+(const Big_int& n1, const Big_int& n2) {
        std::string result = "";
        std::string num1 = n1.num;
        std::string num2 = n2.num;

        // Ensure num1 is the larger number
        if (num1.length() < num2.length()) {
            std::swap(num1, num2);
        }

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        int carry = 0;
        for (size_t i = 0; i < num1.length(); ++i) {
            int digit1 = num1[i] - '0';
            int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        if (carry) {
            result += carry + '0';
        }

        std::reverse(result.begin(), result.end());
        return Big_int(result);
    }

    // For subtraction 

    Big_int operator-(const Big_int& n1, const Big_int& n2) {
    std::string result = "";
    std::string num1 = n1.num;
    std::string num2 = n2.num;

    // Ensure num1 is the larger number
    bool negative = false;
    if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2)) {
        std::swap(num1, num2);
        negative = true;
    }

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    int borrow = 0;
    for (size_t i = 0; i < num1.length(); ++i) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result += diff + '0';
    }

    // Remove leading zeros
    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());

    // Add negative sign if necessary
    if (negative) {
        result = "-" + result;
    }

    return Big_int(result);
}