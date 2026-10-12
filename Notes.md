# Important notes

- we will declare all the declaration files in include folder. and we can separate things like basic declarations, utils, algorithms, exceptions handling, etc

# folder structure may be followed like this

    ```graphql
        BigIntLib/
        │
        ├── include/
        │   ├── BigInt.h                    # BigInt class declarations
        │   ├── BigIntUtils.h               # Utility functions for BigInt
        │   ├── BigIntAlgorithms.h          # Advanced algorithms (Karatsuba, GCD)
        │   ├── BigIntTestUtils.h           # Testing utilities (optional)
        │   └── BigIntExceptions.h          # Custom exception handling (optional)
        │
        ├── src/
        │   ├── BigInt.cpp                  # BigInt class definitions
        │   └── BigIntAlgorithms.cpp        # Implementations for advanced algorithms
        │
        ├── tests/
        │   └── testBigInt.cpp              # Unit tests for BigInt library
        │
        ├── examples/                       # Example programs using the library
        │   └── example.cpp                 # Sample usage of BigInt in an application
        │
        ├── build/                          # Output directory for compiled files
        │
        ├── CMakeLists.txt                  # CMake configuration file (if using CMake)
        │
        ├── LICENSE                         # License file (e.g., MIT License)
        │
        ├── README.md                       # Project README file with documentation
        │
        └── .gitignore                      # Git ignore file for unnecessary files

# Build with CMAKE

```
      # debug: catches bugs, slow
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
# release: for benchmarks only
cmake -B build-rel -DCMAKE_BUILD_TYPE=Release
cmake --build build-rel
```

# starting with project

- For implementing a library in c++, we need to start with implementing a .h header file. it will include all the function declarations, dependencies which are required throughout the project.

- We need to implement the class Bigint. basically it will handle input number of any arbitrary size. So, I am expected to declare a class which under the hood uses string to hold the given input. and need to perform all the necessary string manipulations which can result us with the general operations which can be performed with a regular sized int.

- Throughout the proejct, we are assuming the defined bigint class is a promise that "num holds only digits, no leading zeroes, and zero is never negative". Rest algo and definitions are based on this assumption. so for handling negative numbers, under the hood we will use a is_negative bool data member to represent a number as negative

# BigInt Implementation Roadmap

## Phase 1: Core Skeleton & Basic Representation

- [ ] **Limbs & Sign Design**: Choose internal limb storage (e.g., `std::vector<uint64_t>` or `uint32_t`) and sign management.
- [ ] **Class Invariants**: Define representation rules (e.g., zero has a positive sign and a single zero limb, no unnecessary leading zeros).
- [ ] **String Parsing**: Implement constructors and parsers from string literals and `std::string`.
- [ ] **String Conversion (`to_string`)**: Implement conversion back to decimal string format.
- [ ] **Comparison Operators**: Implement robust relational operators (`==`, `!=`, `<`, `>`, `<=`, `>=`).

## Phase 2: Basic Arithmetic & Infrastructure

- [ ] **Addition & Subtraction**: Implement core arithmetic algorithms with carry/borrow handling.
- [ ] **Stream Operators**: Overload stream insertion (`operator<<`) and extraction (`operator>>`).
- [ ] **Schoolbook Multiplication**: Implement baseline $O(N^2)$ multiplication.
- [ ] **Division & Modulo (`divmod`)**: Implement division algorithms, constructing helpers from standard integer types.
- [ ] **Templates & Overload Resolution**: Handle template construction cleanly to support native integer types without ambiguous overloads.
- [ ] **Rule of 5**: Implement explicit copy/move constructors and assignment operators for efficient memory handling.
- [ ] **Benchmarking Harness**: Set up a performance framework (e.g., Google Benchmark or timing macros) to measure execution time.

## Phase 3: Advanced Optimization

- [ ] **Karatsuba Multiplication**: Implement sub-quadratic multiplication ($O(N^{\log_2 3})$).
- [ ] **Cutoff Tuning**: Run benchmarks with varying input sizes to empirically determine the optimal threshold where Karatsuba outperforms schoolbook multiplication.

## Phase 4 (Optional): Base $2^{32}$ / $2^{64}$ Optimization

- [ ] **Base Migration**: Shift internal storage from base 10 (or base 10) to a power-of-two base ($2^{32}$ or $2^{64}$) to leverage native hardware word sizes.
- [ ] **Speed Comparison**: Benchmark and analyze performance differences against the decimal limb version.
- [ ] **Decimal I/O Challenges**: Investigate and implement division/modulo routines required for efficient decimal input/output with binary-aligned limbs.

# To complile the file

```
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
./build-debug/test_bigint
```
