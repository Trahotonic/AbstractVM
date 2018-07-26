//
// Created by Roman KYSLYY on 7/24/18.
//

#include <fstream>
#include <regex>
#include "../inc/VM.hpp"

VM::VM() {}

VM::VM(VM const &src) {
    *this = src;
}

VM& VM::operator=(VM const &src) {
    _stack = src._stack;
    return *this;
}

VM::~VM() {}

void VM::readInput(int argc, char **argv)
{
	int         count = 1;
	std::string buffer;
	std::cmatch result;
	std::regex  command("(push|assert)([ ])(int8|int16|int32|float|double)(\\()([+|-]?[0-9]*\\.?[0-9]*)(\\))");
	std::regex  fl("([+|-]?[0-9]*\\.[0-9]*)");
	if (argc == 2) {
		std::ifstream fs(argv[1]);
		while (!fs.eof()) {
			std::getline(fs, buffer);
			std::cout << buffer << std::endl;
			count++;
		}
	}
	else
		while (!std::cin.eof()) {
			std::getline(std::cin, buffer);
			if (std::regex_match(buffer.c_str(), result, command)) {
				std::cout << "line \"" << buffer << "\" matches regex\n";
				std::cout << "command: " << result[1] << std::endl;
				std::cout << "data type: " << result[3] << std::endl;
				std::cout << "value: " << result[5] << std::endl;
				if (result[3] == "int8" || result[3] == "int16" || result[3] == "int32") {
					std::string v = result[5];
					if (std::regex_match(v.c_str(), fl)) {
						std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m: ";
						throw FloatIntoIntException();
					}
				}
				count++;
			}
			else {
				std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m: ";
				throw InvalidInput();
			}
		}
}

void VM::add() {
    if (_stack.size() < 2)
	    throw TooFewOperandsException();
    const IOperand    *one = *_stack.begin();
    _stack.pop_front();
    const IOperand    *two = *_stack.begin();
    _stack.pop_front();

	push(*one + *two);
}

void VM::sub() {
	if (_stack.size() < 2)
		throw TooFewOperandsException();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one - *two);
}

void VM::mul() {
	if (_stack.size() < 2)
		throw TooFewOperandsException();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one * *two);
}

void VM::div() {
	if (_stack.size() < 2)
		throw TooFewOperandsException();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one / *two);
}

void VM::mod() {
	if (_stack.size() < 2)
		throw TooFewOperandsException();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one % *two);
}

void VM::push(const IOperand * newOperand) {
    _stack.push_front(newOperand);
}

void VM::pop() {
	if (_stack.empty())
		throw EmptyStackException();
	_stack.pop_front();
}

void VM::dump() {
	for (std::list<const IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
		std::cout << CASTIO(*it)->toString() << std::endl;
	}
}
