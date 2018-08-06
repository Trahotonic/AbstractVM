//
// Created by Roman Kyslyy on 7/28/18.
//

#include "../inc/Token.hpp"

Token::Token() {}

Token::Token(Token const &src) {
    *this = src;
}

Token::Token(eTokens type, std::string const &str) : _type(type), _value(str) {
}

Token& Token::operator=(Token const &src) {
    _type = src._type;
    _value = src._value;
    return *this;
}

Token::~Token() {}

eTokens Token::getType() const {
    return _type;
}

std::string Token::getValue() const {
	return _value;
}

std::string Token::getValueTrim() const {
    size_t i = 0;
	std::string ret = "";
	while (isblank(_value[i]))
		i++;
	while (i < _value.length())
		ret += _value[i++];
    return ret;
}

std::ostream	&operator<<(std::ostream & o, Token const & src) {
    std::string buff;
    if (src.getType() == INSTRUCTION)
        buff = "INSTRUCTION";
    else if (src.getType() == DATATYPE)
        buff = "DATATYPE";
    else if (src.getType() == OPENBRACKET)
        buff = "OPENBRACKET";
    else if (src.getType() == CLOSEBRACKET)
        buff = "CLOSEBRACKET";
    else if (src.getType() == VALUE)
        buff = "VALUE";
    else if (src.getType() == UNKNOWN_DATATYPE)
        buff = "UNKNOWN_DATATYPE";
    else if (src.getType() == UNKNOWN_INSTRUCTION)
        buff = "UNKNOWN_INSTRUCTION";
    else if (src.getType() == MISSING_OPENBRACKET)
        buff = "MISSING_OPENBRACKET";
    else if (src.getType() == MISSING_CLOSEBRACKET)
        buff = "MISSING_CLOSEBRACKET";
    else if (src.getType() == EMPTY_BRACKETS)
        buff = "EMPTY_BRACKETS";
    else if (src.getType() == NOARGS)
        buff = "NOARGS";
    else if (src.getType() == EXCESS_SYMBOLS)
        buff = "EXCESS_SYMBOLS";
    else if (src.getType() == EMPTY_LINE)
        buff = "EMPTY_LINE";
    o << "Type: " << buff << "; Value: " << src.getValue() << std::endl;
    return o;
}
