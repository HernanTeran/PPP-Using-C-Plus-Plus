# CMakeList.txt : CMake project for practice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("practice")

# Add source to this project's executable.
add_executable (practice "Main.cpp" "Main.h"   "Calculator.h" "Calculator.cpp")

# TODO: Add tests and install targets if needed.
