//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

# include "IOperand.hpp"

# include <iostream>
# include <string>

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T				_value;
	std::string		_str;
public:
	Operand() : _type(Int8), _value(0), _str(std::to_string(_value)) {}
	Operand(eOperandType type, T value) : _type(type), _value(value), _str(std::to_string(_value)) {}
	Operand(Operand const &src) {
		*this = src;
	}
	Operand	&operator=(Operand const & src) {
		_type = src._type;
		_value = src._value;
		_str = src._str;
		return *this;
	}
	~Operand() {}

	std::string const & toString() const {
		return _str;
	}

	int getPrecision() const {
		return _type;
	}
	eOperandType getType() const {
		return _type;
	}

};

#endif //ABSTRACTVM_OPERAND_HPP
