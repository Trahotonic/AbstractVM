//
// Created by Roman KYSLYY on 7/24/18.
//

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

std::string VM::getStrSum(const IOperand * one, const IOperand * two) {
	int max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	if (max == Int8)
		return std::to_string(CASTCH(std::stoi(one->toString()) +
									std::stoi(two->toString())));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->toString()) +
		                             std::stoi(two->toString())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->toString()) +
		                      std::stoi(two->toString()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->toString()) +
			                      std::stof(two->toString()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->toString()) +
			                      std::stoi(two->toString()));
		else
			return std::to_string(std::stof(one->toString()) +
			                      std::stof(two->toString()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->toString()) +
				                      std::stoi(two->toString()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->toString()) +
				                      std::stof(two->toString()));
			else
				return std::to_string(std::stod(one->toString()) +
				                      std::stod(two->toString()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->toString()) +
				                      std::stoi(one->toString()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->toString()) +
				                      std::stof(one->toString()));
			else
				return std::to_string(std::stod(two->toString()) +
				                      std::stod(one->toString()));
		}
	}
}

void VM::add() {
    if (_stack.size() < 2) {
        std::cout << "Too few elements in stack\n";
        return ;
    }
    const IOperand    *one = *_stack.begin();
    _stack.pop_front();
    const IOperand    *two = *_stack.begin();
    _stack.pop_front();

	push(*one + *two);
}

void VM::sub() {
	if (_stack.size() < 2) {
		std::cout << "Too few elements in stack\n";
		return ;
	}
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one - *two);
}

void VM::mul() {
	if (_stack.size() < 2) {
		std::cout << "Too few elements in stack\n";
		return ;
	}
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one * *two);
}

void VM::div() {
	if (_stack.size() < 2) {
		std::cout << "Too few elements in stack\n";
		return ;
	}
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one / *two);
}

void VM::mod() {
	if (_stack.size() < 2) {
		std::cout << "Too few elements in stack\n";
		return ;
	}
	const IOperand    *one = *_stack.begin();
	_stack.pop_front();
	const IOperand    *two = *_stack.begin();
	_stack.pop_front();

	push(*one % *two);
}

void VM::push(const IOperand * newOperand) {
    _stack.push_front(newOperand);
}

void VM::dump() {
	for (std::list<const IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
		std::cout << CASTIO(*it)->toString() << std::endl;
	}
}
