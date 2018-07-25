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

IOperand const* VM::createOperand(eOperandType type, std::string const &value) const {
    IOperand const	*(VM::*method[])(std::string const &value) const = {
            &VM::createInt8,
            &VM::createInt16,
            &VM::createInt32,
            &VM::createFloat,
            &VM::createDouble
    };
    return ((this->*method[type])(value));
}

IOperand const* VM::createInt8(std::string const &value) const {
    return new Operand<char>(Int8, static_cast<char>(std::stoi(value)));
}

IOperand const* VM::createInt16(std::string const &value) const {
    return new Operand<short>(Int16, static_cast<short>(std::stoi(value)));
}

IOperand const* VM::createInt32(std::string const &value) const {
    return new Operand<int>(Int32, std::stoi(value));
}

IOperand const* VM::createFloat(std::string const &value) const {
    return new Operand<float>(Float, std::stof(value));
}

IOperand const* VM::createDouble(std::string const &value) const {
    return new Operand<double>(Double, std::stod(value));
}

std::string VM::getStrSum(IOperand * one, IOperand * two) {
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
    IOperand    *one = *_stack.begin();
    _stack.pop_front();
    IOperand    *two = *_stack.begin();
    _stack.pop_front();
	eOperandType max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	createOperand(max, getStrSum(one, two));
}

void VM::push(IOperand * newOperand) {
    _stack.push_front(newOperand);
}

void VM::dump() {
	for (std::list<IOperand*>::iterator it = _stack.begin(); it != _stack.end(); it++) {
		std::cout << CASTIO(*it)->toString() << std::endl;
	}
}
