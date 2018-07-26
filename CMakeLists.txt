cmake_minimum_required(VERSION 3.9)
project(abstractVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(abstractVM src/main.cpp inc/IOperand.hpp src/Operand.cpp inc/Operand.hpp src/VM.cpp inc/VM.hpp src/Converter.cpp inc/Converter.hpp src/Exceptions.cpp inc/Exceptions.hpp src/Factory.cpp inc/Factory.hpp)