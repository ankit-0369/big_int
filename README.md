# BigIntLib

**BigIntLib** is an open-source C++ library aimed at handling integers of arbitrary size, with plans to replicate the complete functionality of standard integers. It will support essential arithmetic operations, comparisons, bitwise manipulations, and advanced functions. This library is intended for use in cryptography, scientific computing, and other applications requiring precise handling of large numbers.

## Planned Features

### Core Features (To be implemented)
- **Basic Arithmetic Operations**:  
  Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/`), Modulus (`%`).
  
- **Comparison Operators**:  
  Equal to (`==`), Not equal to (`!=`), Greater than (`>`), Less than (`<`), Greater than or equal to (`>=`), Less than or equal to (`<=`).
  
- **Bitwise Operations**:  
  AND (`&`), OR (`|`), XOR (`^`), NOT (`~`), Left Shift (`<<`), Right Shift (`>>`).

- **Assignment Operators**:  
  Assignment and compound assignment operators (`=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`).

- **Increment/Decrement**:  
  Pre-increment (`++BigInt`), Post-increment (`BigInt++`), Pre-decrement (`--BigInt`), Post-decrement (`BigInt--`).

### Advanced Features (Planned for future)
- **Modular Arithmetic**:  
  Modular exponentiation and modular inverse for cryptographic applications.

- **Power Operations**:  
  Exponentiation support (`BigInt pow(const BigInt&, int exponent)`).

- **GCD/LCM Calculations**:  
  Compute the greatest common divisor and least common multiple (`BigInt gcd(const BigInt&, const BigInt&)`).

- **String Conversion**:  
  Convert between `BigInt` and string representations (`BigInt fromString(const std::string&)`, `std::string toString(const BigInt&)`).

- **Primality Testing**:  
  Check if a number is prime using the Miller-Rabin algorithm.

- **Random BigInt Generation**:  
  Generate random large integers for cryptographic use.

### Optimizations (To be worked on)
- **Karatsuba Multiplication**:  
  Optimized multiplication algorithm for large integers.
  
- **Memory Management**:  
  Efficient handling of memory for large numbers.
## Installation

1. **Fork the repository**:  
   Go to the GitHub repository and click the "Fork" button in the top-right corner to create a copy of the repository under your GitHub account.

2. **Clone the forked repository**:  
   Clone the repository to your local machine using the following command:
   ```bash
   git clone https://github.com/<your-username>/bigintlib.git

3. **Navigate to the project directory**:
    Change the directory to the cloned repository:
    ```bash
    cd bigIntlib
    ```
4. Usage
    ```cpp
     #include "BigInt.h"

    int main() {
    BigInt a("123456789012345678901234567890");
    BigInt b("987654321098765432109876543210");

    BigInt result = a + b;
    std::cout << "Sum: " << result << std::endl;

    return 0;
    }
    ```
