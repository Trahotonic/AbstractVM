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
	return "Invalid value\n";
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

UnknownCommand::~UnknownCommand() throw() {}

const char* UnknownCommand::UnknownCommand::what() const throw() {
	return "Unknown command\n";
}

UnknownCommand& UnknownCommand::UnknownCommand::operator=(UnknownCommand const &src)
{
	(void)src;
	return *this;
}

UnknownCommand::UnknownCommand() {}

UnknownCommand::UnknownCommand(UnknownCommand const &src) {
	*this = src;
}

ValueOverflow::~ValueOverflow() throw() {}

const char* ValueOverflow::ValueOverflow::what() const throw() {
	return "Value overflow\n";
}

ValueOverflow& ValueOverflow::ValueOverflow::operator=(ValueOverflow const &src)
{
	(void)src;
	return *this;
}

ValueOverflow::ValueOverflow() {}

ValueOverflow::ValueOverflow(ValueOverflow const &src) {
	*this = src;
}

ValueUnderflow::~ValueUnderflow() throw() {}

const char* ValueUnderflow::ValueUnderflow::what() const throw() {
	return "Value underflow\n";
}

ValueUnderflow& ValueUnderflow::ValueUnderflow::operator=(ValueUnderflow const &src)
{
	(void)src;
	return *this;
}

ValueUnderflow::ValueUnderflow() {}

ValueUnderflow::ValueUnderflow(ValueUnderflow const &src) {
	*this = src;
}

DivisionByZero::~DivisionByZero() throw() {}

const char* DivisionByZero::DivisionByZero::what() const throw() {
	return "Division by zero\n";
}

DivisionByZero& DivisionByZero::DivisionByZero::operator=(DivisionByZero const &src)
{
	(void)src;
	return *this;
}

DivisionByZero::DivisionByZero() {}

DivisionByZero::DivisionByZero(DivisionByZero const &src) {
	*this = src;
}

void DivisionByZero::checkZero(int c, const IOperand *one, const IOperand * two, char op) {
    if ((two->getType() == Float && std::stof(two->to_string()) == 0) ||
			(two->getType() == Double && std::stod(two->to_string()) == 0) ||
			(two->getType() != Double && two->getType() != Float && std::stoi(two->to_string()) == 0)) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : \"\e[31m";
		std::cout << one->to_string() << " " << op << " " << two->to_string();
		std::cout << "\e[0m\" - ";
		throw DivisionByZero();
    }

}

NoExit::~NoExit() throw() {}

const char* NoExit::NoExit::what() const throw() {
	return "No exit command\n";
}

NoExit& NoExit::NoExit::operator=(NoExit const &src)
{
	(void)src;
	return *this;
}

NoExit::NoExit() {}

NoExit::NoExit(NoExit const &src) {
	*this = src;
}

AssertFalse::~AssertFalse() throw() {}

const char* AssertFalse::AssertFalse::what() const throw() {
	return "Assertion returned false statement\n";
}

AssertFalse& AssertFalse::AssertFalse::operator=(AssertFalse const &src)
{
	(void)src;
	return *this;
}

AssertFalse::AssertFalse() {}

AssertFalse::AssertFalse(AssertFalse const &src) {
	*this = src;
}

