//
// Created by Roman KYSLYY on 7/24/18.
//

#include <fstream>
#include <regex>
#include <cfloat>
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
    if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot add", c);
    const IOperand    *two = *_stack.begin();
    _stack.pop_front();
    const IOperand    *one = *_stack.begin();
    _stack.pop_front();
	_stack.push_front(*one + *two);
}

void VM::_sub(int c) {
    if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot subtract", c);
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	_stack.push_front(*one - *two);
}

void VM::_mul(int c) {
    if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot multiply", c);
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	_stack.push_front(*one * *two);
}

void VM::_div(int c) {
    if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot divide", c);
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	DivisionByZero::checkZero(c, one, two, '/');
	_stack.push_front(*one / *two);
}

void VM::_mod(int c) {
    if (_stack.size() < 2)
        throw TooFewOperandsException("Cannot modulo", c);
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
    DivisionByZero::checkZero(c, one, two, '%');
	_stack.push_front(*one % *two);
}

void VM::_push(eOperandType type, std::string value) {
	   _stack.push_front(_factory.createOperand(type, value));
}

void VM::_checkAssertionOverflow(eOperandType type, std::string str, int c, std::map<eOperandType, std::string> & types) {
	if ((type == Int8 && std::stol(str) > CHAR_MAX) || (type == Int16 && std::stol(str) > SHRT_MAX)
	    || (type == Int32 && std::stol(str) > INT32_MAX) || (type == Float && std::stof(str) > FLT_MAX)
	    || (type == Double && std::stod(str) > DBL_MAX)) {
		throw ValueOverflow(c, str, "\e[4mInvalid assertion argument\e[24m - <" + types[type] + ">");
	}
	if ((type == Int8 && std::stol(str) < CHAR_MIN) || (type == Int16 && std::stol(str) < SHRT_MIN)
	    || (type == Int32 && std::stol(str) < INT32_MIN) || (type == Float && std::stof(str) < -FLT_MAX)
	    || (type == Double && std::stod(str) < -DBL_MAX)) {
		throw ValueUnderflow(c, str, "\e[4mInvalid assertion argument\e[24m - " + types[type]);
	}
}

void VM::_assertV(eOperandType type, std::string str, int c) {
	std::map<eOperandType, std::string> types = {
			{Int8, "Int8"}, {Int16, "Int16"}, {Int32, "Int32"}, {Float, "Float"}, {Double, "Double"}
	};
	_checkAssertionOverflow(type, str, c, types);
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot assert\e[24m - ";
		throw EmptyStackException();
	}
	if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != Float &&
            dynamic_cast<const IOperand*>(*_stack.begin())->getType() != Double) {
        if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != type ||
            dynamic_cast<const IOperand*>(*_stack.begin())->toString() != str) {
            std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
            std::cout << "(\e[35m" << types[dynamic_cast<const IOperand*>(*_stack.begin())->getType()] << " "
                      << dynamic_cast<const IOperand*>(*_stack.begin())->toString()
                      << "\e[0m) and (\e[33m" << types[type] << " " << str << "\e[0m) - ";
            throw AssertFalse();
        }
	}
	else if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() == Float) {
        if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != type ||
            std::stof(dynamic_cast<const IOperand*>(*_stack.begin())->toString()) != std::stof(str)) {
            std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
            std::cout << "(\e[35m" << types[dynamic_cast<const IOperand*>(*_stack.begin())->getType()] << " "
                      << dynamic_cast<const IOperand*>(*_stack.begin())->toString()
                      << "\e[0m) and (\e[33m" << types[type] << " " << str << "\e[0m) - ";
            throw AssertFalse();
        }
	}
	else {
        if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != type ||
            std::stod(dynamic_cast<const IOperand*>(*_stack.begin())->toString()) != std::stod(str)) {
            std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : ";
            std::cout << "(\e[35m" << types[dynamic_cast<const IOperand*>(*_stack.begin())->getType()] << " "
                      << dynamic_cast<const IOperand*>(*_stack.begin())->toString()
                      << "\e[0m) and (\e[33m" << types[type] << " " << str << "\e[0m) - ";
            throw AssertFalse();
        }
	}
}

void VM::_pop(int c) {
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot pop\e[24m - ";
		throw EmptyStackException();
	}
	_stack.pop_front();
}

std::string VM::_trim(std::string str, eOperandType type) {
	std::ostringstream out;
	if (type == Float)
		out << std::setprecision(2) << std::fixed << std::stof(str);
	else
		out << std::setprecision(2) << std::fixed << std::stod(str);
	return out.str();
}

void VM::_dump(int c) {
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot dump\e[24m - ";
		throw EmptyStackException();
	}
	for (std::list<const IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
		if ((*it)->getType() == Float || (*it)->getType() == Double)
			std::cout << _trim((*it)->toString(), (*it)->getType()) << std::endl;
		else
			std::cout << (*it)->toString() << std::endl;
	}
}

void VM::_print(int c) {
	if (_stack.empty()) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot print\e[24m - ";
		throw EmptyStackException();
	}
	if (_stack.front()->getType() == Int8 &&
        std::stoi(_stack.front()->toString()) >= 32 &&
        std::stoi(_stack.front()->toString()) <= 127)
	    std::cout << static_cast<char>(std::stoi(_stack.front()->toString())) << std::endl;
	else {
        std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \e[4mCannot print\e[24m - ";
        throw NonASCII();
	}
}

void VM::run() {
    typedef void(VM::*meth)(int);
    std::map<std::string, meth> map = {{"add", &VM::_add}, {"sub", &VM::_sub}, {"mul", &VM::_mul},
            {"div", &VM::_div}, {"mod", &VM::_mod}, {"pop", &VM::_pop}, {"print", &VM::_print}, {"dump", &VM::_dump},
    };
	std::vector<MethodData*> methodDatas = _parser.getMethodDatas();
	for (int i = 0; i < static_cast<int>(methodDatas.size()); ++i) {
		if (methodDatas[i]->getInstr() == "push") _push(methodDatas[i]->getType(), methodDatas[i]->getValue());
		else if (methodDatas[i]->getInstr() == "assert") _assertV(methodDatas[i]->getType(), methodDatas[i]->getValue(),
                                                                 methodDatas[i]->getLine());
        else if (methodDatas[i]->getInstr() == "exit") break ;
		else
            (this->*map[methodDatas[i]->getInstr()])(methodDatas[i]->getLine());
	}
}
