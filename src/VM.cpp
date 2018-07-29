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
	std::regex  command("([a-z]*)([ ])(int8|int16|int32|float|double)(\\()([0-9+-]*\\.?[0-9+-]*)(\\))");
	std::regex  op("(add|sub|mul|div|mod|dump)");
	std::regex  fl("([+|-]?[0-9]*\\.[0-9]*)");
	std::regex  in("([+|-]?[0-9]*[0-9]*)");
	if (argc == 2) {
		std::ifstream fs(argv[1]);
		while (true) {
			std::getline(fs, buffer);
            if (std::regex_match(buffer.c_str(), result, command)) {
//				std::cout << "line \"" << buffer << "\" matches regex\n";
//				std::cout << "command: " << result[1] << std::endl;
//				std::cout << "data type: " << result[3] << std::endl;
//				std::cout << "value: " << result[5] << std::endl;
                std::string v = result[5];
                if (result[3] == "int8" || result[3] == "int16" || result[3] == "int32") {
                    if (!std::regex_match(v.c_str(), in)) {
                        std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m : \"";
                        for (int i = 1; i < static_cast<int>(result.size()); i++) {
                            if (i != 5)
                                std::cout << result[i];
                            else
                                std::cout << "\e[31m" << result[i] << "\e[0m";
                        }
                        std::cout << "\" - ";
                        throw FloatIntoIntException();
                    }
                }
                else
                if (!std::regex_match(v.c_str(), fl)) {
                    std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m : ";
                    for (int i = 1; i < static_cast<int>(result.size()); i++) {
                        if (i != 5)
                            std::cout << result[i];
                        else
                            std::cout << "\e[31m" << result[i] << "\e[0m";
                    }
                    std::cout << "\" - ";
                    throw FloatIntoIntException();
                }
                if (result[1] == "push") {
                    if (result[3] == "int8")
                        push(Int8, result[5]);
                    else if (result[3] == "int16")
                        push(Int16, result[5]);
                    else if (result[3] == "int32")
                        push(Int32, result[5]);
                    else if (result[3] == "float")
                        push(Float, result[5]);
                    else
                        push(Double, result[5]);
                }
                else if (result[1] == "assert")
                    std::cout << "OK\n";
                else {
                    std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m : \"";
                    for (int i = 1; i < static_cast<int>(result.size()); i++) {
                        if (i != 1)
                            std::cout << result[i];
                        else
                            std::cout << "\e[31m" << result[i] << "\e[0m";
                    }
                    std::cout << "\" - ";
                    throw UnknownCommand();
                }
                count++;
                line++;
            }
            else if (std::regex_match(buffer.c_str(), result, op)) {
                if (result[0] == "add")
                    add(count);
                else if (result[0] == "sub")
                    sub(count);
                else if (result[0] == "sub")
                    mul(count);
                else if (result[0] == "div")
                    div(count);
                else if (result[0] == "mod")
                    mod(count);
                else
                    dump();
            }
            else {
                std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m : ";
                throw InvalidInput();
            }
			count++;
            line++;
            if (fs.eof())
                break ;
		}
	}
	else
		while (true) {
			std::getline(std::cin, buffer);
			if (std::cin.eof())
				break ;
			if (std::regex_match(buffer.c_str(), result, command)) {
//				std::cout << "line \"" << buffer << "\" matches regex\n";
//				std::cout << "command: " << result[1] << std::endl;
//				std::cout << "data type: " << result[3] << std::endl;
//				std::cout << "value: " << result[5] << std::endl;
				if (result[3] == "int8" || result[3] == "int16" || result[3] == "int32") {
					std::string v = result[5];
					if (std::regex_match(v.c_str(), fl)) {
						std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m : ";
						throw FloatIntoIntException();
					}
				}
				if (result[1] == "push") {
					if (result[3] == "int8")
						push(Int8, result[5]);
					else if (result[3] == "int16")
						push(Int16, result[5]);
					else if (result[3] == "int32")
						push(Int32, result[5]);
					else if (result[3] == "float")
						push(Float, result[5]);
					else
						push(Double, result[5]);
				}
				count++;
                line++;
			}
			else if (std::regex_match(buffer.c_str(), result, op)) {
			    if (result[0] == "add")
			        add(count);
			    else if (result[0] == "sub")
			        sub(count);
                else if (result[0] == "sub")
                    mul(count);
                else if (result[0] == "sub")
                    div(count);
                else if (result[0] == "mod")
                    mod(count);
                else
                    dump();
			}
			else {
				std::cout << "\e[4mLine " << count << "\e[24m : \e[31mError\e[0m : ";
				throw InvalidInput();
			}
		}
}

void VM::add(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
        throw TooFewOperandsException();
    }
    const IOperand    *one = *_stack.begin();
    _stack.pop_front();
    const IOperand    *two = *_stack.begin();
    _stack.pop_front();

	_stack.push_front(*one + *two);
}

void VM::sub(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	_stack.push_front(*one - *two);
}

void VM::mul(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	_stack.push_front(*one * *two);
}

void VM::div(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();
	DivisionByZero::checkZero(c, one, two, '/');
	_stack.push_front(*one / *two);
}

void VM::mod(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	_stack.push_front(*one % *two);
}

void VM::push(eOperandType type, std::string value) {
	   _stack.push_front(_factory.createOperand(type, value));
}

void VM::assertV(eOperandType type, std::string str) {
    if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() == type &&
        dynamic_cast<const IOperand*>(*_stack.begin())->to_string() == str)
        return ;
    throw AssertFalse();
}

void VM::pop() {
	if (_stack.empty())
		throw EmptyStackException();
	_stack.pop_front();
}

void VM::dump() {
	for (std::list<const IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
		std::cout << CASTIO(*it)->to_string() << std::endl;
	}
}
