//
// Created by Roman KYSLYY on 7/26/18.
//

#include "../inc/Exceptions.hpp"

EmptyStackException::~EmptyStackException() throw() {}

const char* EmptyStackException::EmptyStackException::what() const throw() {
	return "Stack is empty";
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
	return "Too few operands in stack";
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
	return "Invalid value";
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
	return "Invalid value";
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
	return "Unknown instruction";
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
	return "value overflow";
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
	return "value underflow";
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
	return "Division by zero";
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
    if ((two->getType() == Float && std::stof(two->toString()) == 0) ||
			(two->getType() == Double && std::stod(two->toString()) == 0) ||
			(two->getType() != Double && two->getType() != Float && std::stoi(two->toString()) == 0)) {
		std::cout << "\e[4mLine " << c << "\e[24m : \e[31mError\e[0m : [";
		std::cout << one->toString() << " " << op << " \e[31m" << two->toString();
		std::cout << "\e[0m] - ";
		throw DivisionByZero();
    }

}

NoExit::~NoExit() throw() {}

const char* NoExit::NoExit::what() const throw() {
	return "No exit command";
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
	return "Assertion returned false statement";
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

UnknownDataType::~UnknownDataType() throw() {}

const char* UnknownDataType::UnknownDataType::what() const throw() {
	return "Unknown data type";
}

UnknownDataType& UnknownDataType::UnknownDataType::operator=(UnknownDataType const &src)
{
	(void)src;
	return *this;
}

UnknownDataType::UnknownDataType() {}

UnknownDataType::UnknownDataType(UnknownDataType const &src) {
	*this = src;
}

NoOpenBracket::~NoOpenBracket() throw() {}

const char* NoOpenBracket::NoOpenBracket::what() const throw() {
	return "Missing opening bracket";
}

NoOpenBracket& NoOpenBracket::NoOpenBracket::operator=(NoOpenBracket const &src)
{
	(void)src;
	return *this;
}

NoOpenBracket::NoOpenBracket() {}

NoOpenBracket::NoOpenBracket(NoOpenBracket const &src) {
	*this = src;
}

NoCloseBracket::~NoCloseBracket() throw() {}

const char* NoCloseBracket::NoCloseBracket::what() const throw() {
	return "Missing closing bracket";
}

NoCloseBracket& NoCloseBracket::NoCloseBracket::operator=(NoCloseBracket const &src)
{
	(void)src;
	return *this;
}

NoCloseBracket::NoCloseBracket() {}

NoCloseBracket::NoCloseBracket(NoCloseBracket const &src) {
	*this = src;
}


EmptyBrackets::~EmptyBrackets() throw() {}

const char* EmptyBrackets::EmptyBrackets::what() const throw() {
	return "Empty brackets";
}

EmptyBrackets& EmptyBrackets::EmptyBrackets::operator=(EmptyBrackets const &src)
{
	(void)src;
	return *this;
}

EmptyBrackets::EmptyBrackets() {}

EmptyBrackets::EmptyBrackets(EmptyBrackets const &src) {
	*this = src;
}

NoArgs::~NoArgs() throw() {}

const char* NoArgs::NoArgs::what() const throw() {
	return "No arguments provided";
}

NoArgs& NoArgs::NoArgs::operator=(NoArgs const &src)
{
	(void)src;
	return *this;
}

NoArgs::NoArgs() {}

NoArgs::NoArgs(NoArgs const &src) {
	*this = src;
}

Excess::~Excess() throw() {}

const char* Excess::Excess::what() const throw() {
	return "Excess symbols in the end of line";
}

Excess& Excess::Excess::operator=(Excess const &src)
{
	(void)src;
	return *this;
}

Excess::Excess() {}

Excess::Excess(Excess const &src) {
	*this = src;
}

MissingDataType::~MissingDataType() throw() {}

const char* MissingDataType::MissingDataType::what() const throw() {
	return "Missing data type";
}

MissingDataType& MissingDataType::MissingDataType::operator=(MissingDataType const &src)
{
	(void)src;
	return *this;
}

MissingDataType::MissingDataType() {}

MissingDataType::MissingDataType(MissingDataType const &src) {
	*this = src;
}

NonASCII::~NonASCII() throw() {}

const char* NonASCII::NonASCII::what() const throw() {
	return "value is invalid to be printed as ASCII character";
}

NonASCII& NonASCII::NonASCII::operator=(NonASCII const &src)
{
	(void)src;
	return *this;
}

NonASCII::NonASCII() {}

NonASCII::NonASCII(NonASCII const &src) {
	*this = src;
}

ParsingError::~ParsingError() throw() {}

const char* ParsingError::ParsingError::what() const throw() {
	return "\n\e[31mProgram cannot be executed\e[0m";
}

ParsingError& ParsingError::ParsingError::operator=(ParsingError const &src)
{
	(void)src;
	return *this;
}

ParsingError::ParsingError() {}

ParsingError::ParsingError(ParsingError const &src) {
	*this = src;
}

MissingExit::~MissingExit() throw() {}

const char* MissingExit::MissingExit::what() const throw() {
	return "\"exit\" command is missing";
}

MissingExit& MissingExit::MissingExit::operator=(MissingExit const &src)
{
	(void)src;
	return *this;
}

MissingExit::MissingExit() {}

MissingExit::MissingExit(MissingExit const &src) {
	*this = src;
}
