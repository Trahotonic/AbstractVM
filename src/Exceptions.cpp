//
// Created by Roman KYSLYY on 7/26/18.
//

#include "../inc/Exceptions.hpp"

EmptyStackException::~EmptyStackException() throw() {}

const char* EmptyStackException::EmptyStackException::what() const throw() {
	return "Stack is empty\n";
}

EmptyStackException& EmptyStackException::EmptyStackException::operator=(EmptyStackException const &src)
{
	(void)src;
	return *this;
}

EmptyStackException::EmptyStackException() {}

EmptyStackException::EmptyStackException(EmptyStackException const &src) {
	*this = src;
}

TooFewOperandsException::~TooFewOperandsException() throw() {}

const char* TooFewOperandsException::TooFewOperandsException::what() const throw() {
	return "Too few operands in stack\n";
}

TooFewOperandsException& TooFewOperandsException::TooFewOperandsException::operator=(TooFewOperandsException const &src)
{
	(void)src;
	return *this;
}

TooFewOperandsException::TooFewOperandsException() {}

TooFewOperandsException::TooFewOperandsException(TooFewOperandsException const &src) {
	*this = src;
}

FloatIntoIntException::~FloatIntoIntException() throw() {}

const char* FloatIntoIntException::FloatIntoIntException::what() const throw() {
	return "Incompatible type and value\n";
}

FloatIntoIntException& FloatIntoIntException::operator=(FloatIntoIntException const &src)
{
	(void)src;
	return *this;
}

FloatIntoIntException::FloatIntoIntException() {}

FloatIntoIntException::FloatIntoIntException(FloatIntoIntException const &src) {
	*this = src;
}

InvalidInput::~InvalidInput() throw() {}

const char* InvalidInput::InvalidInput::what() const throw() {
	return "Invalid input\n";
}

InvalidInput& InvalidInput::operator=(InvalidInput const &src)
{
	(void)src;
	return *this;
}

InvalidInput::InvalidInput() {}

InvalidInput::InvalidInput(InvalidInput const &src) {
	*this = src;
}

