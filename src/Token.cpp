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
