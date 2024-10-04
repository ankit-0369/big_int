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




# starting with project

* For implementing a library in c++, we need to start with implementing a .h header file. it will include all the function declarations, dependencies which are required throughout the project.

* We need to implement the class Bigint. basically it will handle input number of any arbitrary size. So, I am expected to declare a class which under the hood uses string to hold the given input. and need to perform all the necessary string manipulations which can result us with the general operations which can be performed with a regular sized int.

