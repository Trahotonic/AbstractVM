cmake_minimum_required(VERSION 3.9)
project(abstractVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(abstractVM src/main.cpp inc/IOperand.hpp inc/Operand.hpp src/VM.cpp inc/VM.hpp src/Exceptions.cpp inc/Exceptions.hpp src/Factory.cpp inc/Factory.hpp src/Lexer.cpp inc/Lexer.hpp src/Token.cpp inc/Token.hpp src/Parser.cpp inc/Parser.hpp src/MethodData.cpp inc/MethodData.hpp src/Visualizer.cpp inc/Visualizer.hpp)