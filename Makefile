# Define compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

# Define directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Define target executable
TARGET = $(BUILD_DIR)/BigIntApp.exe  # For Windows, use .exe extension

# Source files and object files
SRC = $(INCLUDE_DIR)/big_int.cpp $(SRC_DIR)/main.cpp
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
	del /Q $(BUILD_DIR)\*.o $(TARGET)