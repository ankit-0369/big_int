# cmake_minimum_required(VERSION 3.10)

# # Project name
# project(BigIntLib)

# # C++ version
# set(CMAKE_CXX_STANDARD 17)

# # Include directories
# include_directories(include)

# # Add library (BigIntLib)
# add_library(BigIntLib src/BigInt.cpp)

# # Create executable for running main.cpp
# add_executable(BigIntApp src/main.cpp)

# # Link BigIntLib to the main executable
# target_link_libraries(BigIntApp BigIntLib)



cmake_minimum_required(VERSION 3.16)
project(bigint CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bigint src/bigint.cpp)
target_include_directories(bigint PUBLIC include)
target_compile_options(bigint PRIVATE -Wall -Wextra -Wpedantic)

add_executable(test_bigint tests/test_bigint.cpp)
target_link_libraries(test_bigint PRIVATE bigint)

add_executable(rough tests/rough_work.cpp)
target_link_libraries(rough PRIVATE bigint)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  foreach(t bigint test_bigint rough)
    target_compile_options(${t} PRIVATE -fsanitize=address,undefined)
    target_link_options(${t} PRIVATE -fsanitize=address,undefined)
  endforeach()
endif()


