//
// Created by Roman KYSLYY on 7/26/18.
//

#include "../inc/Exceptions.hpp"

EmptyStackException::EmptyStackException::~EmptyStackException() throw() {}

const char* EmptyStackException::EmptyStackException::what() const throw() {
	return "Stack is empty\n";
}

EmptyStackException::EmptyStackException::EmptyStackException() {}

EmptyStackException::EmptyStackException::EmptyStackException(EmptyStackException const &src) {
	*this = src;
}

TooFewOperandsException::TooFewOperandsException::~TooFewOperandsException() throw() {}

const char* TooFewOperandsException::TooFewOperandsException::what() const throw() {
	return "Too few operands in stack\n";
}

TooFewOperandsException::TooFewOperandsException::TooFewOperandsException() {}

TooFewOperandsException::TooFewOperandsException::TooFewOperandsException(TooFewOperandsException const &src) {
	*this = src;
}

