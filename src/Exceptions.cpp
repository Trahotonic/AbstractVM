//
// Created by Roman KYSLYY on 7/26/18.
//

#include "../inc/Exceptions.hpp"

std::string printFirstRed(std::string line) {
	size_t i = 0;
	std::stringstream ss;
	while (isblank(line[i]))
		ss << line[i++];
	ss << "\e[31m";
	while (i < static_cast<size_t>(line.size())) {
		ss << line[i++];
		if (i >= static_cast<size_t>(line.size()) || isblank(line[i]) || line[i] == '(') {
			ss << "\e[0m";
		}
	}
	ss <<  "\" - ";
	return ss.str();
}

EmptyStackException::~EmptyStackException() throw() {}

const char* EmptyStackException::EmptyStackException::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : \e[4m" + _str +
		  "\e[24m - Stack is empty";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

EmptyStackException::EmptyStackException(std::string str, int line) : _str(str), _line(line) {}

TooFewOperandsException::~TooFewOperandsException() throw() {}

const char* TooFewOperandsException::TooFewOperandsException::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : \e[4m" + _str +
			"\e[24m - Too few operands in stack";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

TooFewOperandsException::TooFewOperandsException(std::string str, int line) : _str(str), _line(line) {}

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
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : \"" + _tokens[0]->getValueTrim() + " " +
			_tokens[1]->getValueTrim() + _tokens[2]->getValueTrim() + "\e[31m" +
			_tokens[3]->getValueTrim() + "\e[0m" + _tokens[4]->getValueTrim() + "\" - Invalid value";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

InvalidInput::InvalidInput(std::vector<Token *> tokens, int line) : _tokens(tokens), _line(line) {}

UnknownCommand::~UnknownCommand() throw() {}

const char* UnknownCommand::UnknownCommand::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = printFirstRed(_tokens[0]->getValue()) + "Unknown instruction";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

UnknownCommand::UnknownCommand(std::vector<Token *> tokens) : _tokens(tokens) {}

ValueOverflow::~ValueOverflow() throw() {}

const char* ValueOverflow::ValueOverflow::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : [\e[31m" +
			_value + "\e[0m] - " + _type + " value overflow";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

ValueOverflow::ValueOverflow(int line, std::string value, std::string type) : _line(line), _value(value), _type(type) {}

ValueUnderflow::~ValueUnderflow() throw() {}

const char* ValueUnderflow::ValueUnderflow::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : [\e[31m" +
		  _value + "\e[0m] - " + _type + " value underflow";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

ValueUnderflow::ValueUnderflow(int line, std::string value, std::string type) : _line(line), _value(value), _type(type)
{}

DivisionByZero::~DivisionByZero() throw() {}

const char* DivisionByZero::DivisionByZero::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : [" + _value1 + " " + _op + " \e[31m" +
			_value2 + "\e[0m] - ";
	if (_op == '/')
		str += "Division";
	else
		str += "Modulo";
	str += " by zero";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

DivisionByZero::DivisionByZero(int line, std::string const &value1, std::string const &value2, char op) :
_line(line), _value1(value1), _value2(value2), _op(op) {}

void DivisionByZero::checkZero(int c, const IOperand *one, const IOperand * two, char op) {
	if ((two->getType() == Float && std::stof(two->toString()) == 0) ||
			(two->getType() == Double && std::stod(two->toString()) == 0) ||
			(two->getType() != Double && two->getType() != Float && std::stoi(two->toString()) == 0)) {
		throw DivisionByZero(c, one->toString(), two->toString(), op);
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
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : (\e[35m" + _type1 + " " + _value1 +
			"\e[0m) and (\e[33m" + _type2 + " " + _value2 + "\e[0m) - " + "Assertion failed";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

AssertFalse::AssertFalse(std::string type1, std::string type2, std::string value1, std::string value2,
						 int line, std::map<eOperandType, std::string> types) :
_type1(type1), _type2(type2), _value1(value1), _value2(value2), _line(line), _types(types) {}

UnknownDataType::~UnknownDataType() throw() {}

const char* UnknownDataType::UnknownDataType::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = _tokens[0]->getValue() + printFirstRed(_tokens[1]->getValue()) + "Unknown data type";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

UnknownDataType::UnknownDataType(std::vector<Token *> tokens) : _tokens(tokens) {}

NoOpenBracket::~NoOpenBracket() throw() {}

const char* NoOpenBracket::NoOpenBracket::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = _tokens[0]->getValue() + _tokens[1]->getValue() + "\e[31m!\e[0m" + _tokens[2]->getValue() +
			" - Missing opening bracket";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

NoOpenBracket::NoOpenBracket(std::vector<Token *> tokens) : _tokens(tokens) {}

NoCloseBracket::~NoCloseBracket() throw() {}

const char* NoCloseBracket::NoCloseBracket::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = _tokens[0]->getValue() + _tokens[1]->getValue() + _tokens[2]->getValue() + _tokens[3]->getValue() +
			printFirstRed(_tokens[4]->getValue()) + "Missing closing bracket";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

NoCloseBracket::NoCloseBracket(std::vector<Token *> tokens) : _tokens(tokens) {}

EmptyBrackets::~EmptyBrackets() throw() {}

const char* EmptyBrackets::EmptyBrackets::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = _tokens[0]->getValue() + _tokens[1]->getValue() + printFirstRed(_tokens[2]->getValue()) + "Empty brackets";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

EmptyBrackets::EmptyBrackets(std::vector<Token *> tokens) : _tokens(tokens) {}

NoArgs::~NoArgs() throw() {}

const char* NoArgs::NoArgs::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = _tokens[0]->getValue() + " " + _tokens[1]->getValue() + printFirstRed(_tokens[2]->getValue()) +
			"No arguments provided";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

NoArgs::NoArgs(std::vector<Token *> tokens) : _tokens(tokens) {}

Excess::~Excess() throw() {}

const char* Excess::Excess::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	if (_tokens[0]->getValue() == "push" || _tokens[0]->getValue() == "assert")
		str = _tokens[0]->getValue() + " " + _tokens[1]->getValue() + _tokens[2]->getValue() + _tokens[3]->getValue() +
				_tokens[4]->getValue() + "\e[31m" + _tokens[5]->getValue();
	else
		str = _tokens[0]->getValue() + "\e[31m" + _tokens[1]->getValue();
	size = str.length() + strlen("\e[0m\" - Excess symbols in the end of line") + 20;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	strcat(ret, "\e[0m\" - Excess symbols in the end of line");
	return ret;
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

Excess::Excess(std::vector<Token *> tokens) : _tokens(tokens){}

MissingDataType::~MissingDataType() throw() {}

const char* MissingDataType::MissingDataType::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = _tokens[0]->getValue() + " \e[31m" + _tokens[1]->getValue() + "\e[0m\" - Data type missing";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

MissingDataType::MissingDataType(std::vector<Token *> tokens) : _tokens(tokens) {}

NonASCII::~NonASCII() throw() {}

const char* NonASCII::NonASCII::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[4mLine " + std::to_string(_line) + "\e[24m : \e[31mError\e[0m : \e[4mCannot print\e[24m - value [\e[33m" +
			_value + "\e[0m] is invalid to be printed as ASCII character";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
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

NonASCII::NonASCII(int line, std::string const &value) : _line(line), _value(value) {}

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
	return "\e[31mError : Couldn`t find program exit\nAbort\e[0m";
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

UnexpectedEnd::~UnexpectedEnd() throw() {}

const char* UnexpectedEnd::UnexpectedEnd::what() const throw() {
	return "Unexpected end of stream";
}

UnexpectedEnd& UnexpectedEnd::UnexpectedEnd::operator=(UnexpectedEnd const &src)
{
	(void)src;
	return *this;
}

UnexpectedEnd::UnexpectedEnd() {}

UnexpectedEnd::UnexpectedEnd(UnexpectedEnd const &src) {
	*this = src;
}

FileDoesNotExist::~FileDoesNotExist() throw() {}

const char* FileDoesNotExist::FileDoesNotExist::what() const throw() {
	char				*ret;
	unsigned long	   size;
	std::string		 str;

	str = "\e[31mError\e[0m : file \"" + _fileName + "\" does not exist";
	size = str.length() + 2;
	ret = new char[size];
	for (unsigned long i = 0; i < size; ++i)
		ret[i] = '\0';
	strcat(ret, str.c_str());
	return ret;
}

FileDoesNotExist& FileDoesNotExist::FileDoesNotExist::operator=(FileDoesNotExist const &src)
{
	(void)src;
	return *this;
}

FileDoesNotExist::FileDoesNotExist() {}

FileDoesNotExist::FileDoesNotExist(FileDoesNotExist const &src) {
	*this = src;
}

FileDoesNotExist::FileDoesNotExist(std::string fileName) : _fileName(fileName) {}


InvalidArguments::~InvalidArguments() throw() {}

const char* InvalidArguments::InvalidArguments::what() const throw() {
	return "\e[31mError\e[0m : Invalid arguments";
}

InvalidArguments& InvalidArguments::InvalidArguments::operator=(InvalidArguments const &src)
{
	(void)src;
	return *this;
}

InvalidArguments::InvalidArguments() {}

InvalidArguments::InvalidArguments(InvalidArguments const &src) {
	*this = src;
}

