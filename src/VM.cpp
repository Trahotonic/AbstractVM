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
