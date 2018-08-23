/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:08:11 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:08:12 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <regex>
#include <cfloat>
#include "../inc/VM.hpp"

VM::VM() : _visualization(false) {}

VM::VM(VM const &src) {
	*this = src;
}

VM& VM::operator=(VM const &src) {
	_stack = src._stack;
	return *this;
}

VM::~VM() {}

void VM::readInput(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		if (!strcmp(argv[i], "-v"))
			_visualization = true;
	}
	_lexer.readInput(argc, argv);
	_parser.setTokens(_lexer.getTokens());
	_parser.parseTokens();
}

void VM::_add(int c) {
	if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot add", c);
	const IOperand	*two = *_stack.begin();
	_stack.pop_front();
	const IOperand	*one = *_stack.begin();
	_stack.pop_front();
	_stack.push_front(*one + *two);
}

void VM::_sub(int c) {
	if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot subtract", c);
	const IOperand	*two = *_stack.begin();
	_stack.pop_front();
	const IOperand	*one = *_stack.begin();
	_stack.pop_front();
	_stack.push_front(*one - *two);
}

void VM::_mul(int c) {
	if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot multiply", c);
	const IOperand	*two = *_stack.begin();
	_stack.pop_front();
	const IOperand	*one = *_stack.begin();
	_stack.pop_front();
	_stack.push_front(*one * *two);
}

void VM::_div(int c) {
	if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot divide", c);
	const IOperand	*two = *_stack.begin();
	_stack.pop_front();
	const IOperand	*one = *_stack.begin();
	_stack.pop_front();
	DivisionByZero::checkZero(c, one, two, '/');
	_stack.push_front(*one / *two);
}

void VM::_mod(int c) {
	if (_stack.size() < 2)
		throw TooFewOperandsException("Cannot modulo", c);
	const IOperand	*two = *_stack.begin();
	_stack.pop_front();
	const IOperand	*one = *_stack.begin();
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
			{Int8, "Int8"}, {Int16, "Int16"}, {Int32, "Int32"},
			{Float, "Float"}, {Double, "Double"}
	};
	_checkAssertionOverflow(type, str, c, types);
	if (_stack.empty()) {
		throw EmptyStackException("Cannot assert", c);
	}
	if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != Float &&
			dynamic_cast<const IOperand*>(*_stack.begin())->getType() != Double) {
		if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != type ||
			dynamic_cast<const IOperand*>(*_stack.begin())->toString() != str) {
			throw AssertFalse(types[dynamic_cast<const IOperand*>(*_stack.begin())->getType()],
							  types[type], dynamic_cast<const IOperand*>(*_stack.begin())->toString(), str, c, types);
		}
	}
	else if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() == Float) {
		if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != type ||
			std::stof(dynamic_cast<const IOperand*>(*_stack.begin())->toString()) != std::stof(str)) {
			throw AssertFalse(types[dynamic_cast<const IOperand*>(*_stack.begin())->getType()],
							  types[type], dynamic_cast<const IOperand*>(*_stack.begin())->toString(), str, c, types);
		}
	}
	else {
		if (dynamic_cast<const IOperand*>(*_stack.begin())->getType() != type ||
			std::stod(dynamic_cast<const IOperand*>(*_stack.begin())->toString()) != std::stod(str)) {
			throw AssertFalse(types[dynamic_cast<const IOperand*>(*_stack.begin())->getType()],
							  types[type], dynamic_cast<const IOperand*>(*_stack.begin())->toString(), str, c, types);
		}
	}
}

void VM::_pop(int c) {
	if (_stack.empty()) {
		throw EmptyStackException("Cannot pop", c);
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
		throw EmptyStackException("Cannot dump", c);
	}
	if (!_visualization)
		for (std::list<const IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
			if ((*it)->getType() == Float || (*it)->getType() == Double)
				std::cout << _trim((*it)->toString(), (*it)->getType()) << std::endl;
			else
				std::cout << (*it)->toString() << std::endl;
		}
}

void VM::_print(int c) {
	if (_visualization)
		return ;
	if (_stack.empty()) {
		throw EmptyStackException("Cannot print", c);
	}
	if (_stack.front()->getType() == Int8 &&
		std::stoi(_stack.front()->toString()) >= 32 &&
		std::stoi(_stack.front()->toString()) <= 127)
		std::cout << static_cast<char>(std::stoi(_stack.front()->toString())) << std::endl;
	else {
		throw NonASCII(c, _stack.front()->toString());
	}
}

void VM::run() {
	if (_visualization)
		_visualizer.initVis();
	typedef void(VM::*meth)(int);
	std::map<std::string, meth> map = {{"add", &VM::_add}, {"sub", &VM::_sub},
									   {"mul", &VM::_mul}, {"div", &VM::_div},
									   {"mod", &VM::_mod}, {"pop", &VM::_pop},
									   {"print", &VM::_print},
									   {"dump", &VM::_dump},
	};
	std::vector<MethodData*> methodDatas = _parser.getMethodDatas();
	for (int i = 0; i < static_cast<int>(methodDatas.size()); ++i) {
		try {
			if (_visualization)
				_visualizer.visualize(_stack, methodDatas, i);
			if (_visualizer.getExit())
				break ;
			if (methodDatas[i]->getInstr() == "push")
				_push(methodDatas[i]->getType(), methodDatas[i]->getValue());
			else if (methodDatas[i]->getInstr() == "assert")
				_assertV(methodDatas[i]->getType(), methodDatas[i]->getValue(),
						 methodDatas[i]->getLine());
			else if (methodDatas[i]->getInstr() == "exit")
				break ;
			else
				(this->*map[methodDatas[i]->getInstr()])(methodDatas[i]->getLine());
		}
		catch (std::exception & e) {
			if (_visualization) {
				_visualization = false;
				_visualizer.endWithError();
			}
			std::cout << e.what() << std::endl;
			break ;
		}
	}
	if (_visualization)
		endwin();
}
