# Important notes

* we will declare all the declaration files in include folder. and we can separate things like basic declarations, utils, algorithms, exceptions handling, etc

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

```