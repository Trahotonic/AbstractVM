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

void VM::readInput(int argc, char **argv) {
	_lexer.readInput(argc, argv);
	_parser.setTokens(_lexer.getTokens());
	_parser.parseTokens();
}

void VM::_add(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot add\e[24m - ";
        throw TooFewOperandsException();
    }
    const IOperand    *one = *_stack.begin();
    _stack.pop_front();
    const IOperand    *two = *_stack.begin();
    _stack.pop_front();

	_stack.push_front(*one + *two);
}

void VM::_sub(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot subtract\e[24m - ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	_stack.push_front(*one - *two);
}

void VM::_mul(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot multiply\e[24m - ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	_stack.push_front(*one * *two);
}

void VM::_div(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot divide\e[24m - ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();
	DivisionByZero::checkZero(c, one, two, '/');
	_stack.push_front(*one / *two);
}

void VM::_mod(int c) {
    if (_stack.size() < 2) {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot modulo\e[24m - ";
        throw TooFewOperandsException();
    }
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	_stack.push_front(*one % *two);
}

void VM::_push(eOperandType type, std::string value) {
	   _stack.push_front(_factory.createOperand(type, value));
}

void VM::_assertV(eOperandType type, std::string str, int c) {
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot assert\e[24m - ";
		throw EmptyStackException();
	}
    if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() == type &&
        dynamic_cast<const IOperand*>(*_stack.begin())->to_string() == str)
        return ;
    throw AssertFalse();
}

void VM::_pop(int c) {
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot pop\e[24m - ";
		throw EmptyStackException();
	}
	_stack.pop_front();
}

void VM::_dump(int c) {
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot dump\e[24m - ";
		throw EmptyStackException();
	}
	for (std::list<const IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
		std::cout << CASTIO(*it)->to_string() << std::endl;
	}
}

void VM::run() {
	std::vector<MethodData*> methodDatas = _parser.getMethodDatas();
	for (int i = 0; i < static_cast<int>(methodDatas.size()); ++i) {
		if (methodDatas[i]->getInstr() == "push")
			_push(methodDatas[i]->getType(), methodDatas[i]->getValue());
		else if (methodDatas[i]->getInstr() == "assert") {
			_assertV(methodDatas[i]->getType(), methodDatas[i]->getValue(), methodDatas[i]->getLine());
		}
		else if (methodDatas[i]->getInstr() == "add")
			_add(methodDatas[i]->getLine());
		else if (methodDatas[i]->getInstr() == "sub")
			_sub(methodDatas[i]->getLine());
		else if (methodDatas[i]->getInstr() == "mul")
			_mul(methodDatas[i]->getLine());
		else if (methodDatas[i]->getInstr() == "div")
			_div(methodDatas[i]->getLine());
		else if (methodDatas[i]->getInstr() == "mod")
			_mod(methodDatas[i]->getLine());
        else if (methodDatas[i]->getInstr() == "dump")
            _dump(methodDatas[i]->getLine());
        else if (methodDatas[i]->getInstr() == "mod")
            _mod(methodDatas[i]->getLine());
		else if (methodDatas[i]->getInstr() == "pop")
			_pop(methodDatas[i]->getLine());
	}
}
