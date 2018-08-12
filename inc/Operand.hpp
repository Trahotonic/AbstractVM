//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>
# include <cmath>

# include "IOperand.hpp"
# include "Factory.hpp"

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T				_value;
	std::string		_str;
	Factory         _factory;

public:
	Operand() : _type(Int8), _value(0), _str(to_string(_value)) {}
	Operand(eOperandType type, T value) : _type(type), _value(value), _str(to_string(_value)) {}
	Operand(eOperandType type, T value, std::string str) : _type(type), _value(value), _str(str) {}
	Operand(Operand const &src) {
		*this = src;
	}
	Operand	&operator=(Operand const & src) {
		_type = src._type;
		_value = src._value;
		_str = src._str;
		return *this;
	}

	T   getValue() const {
        return _value;
    }

	~Operand() {}

	template <typename X>
	std::string to_string(const X a_value)
	{
		std::ostringstream out;
		if (typeid(a_value) == typeid(char))
			out << std::setprecision(2) << std::fixed << static_cast<int>(a_value);
		else
			out << std::setprecision(2) << std::fixed << a_value;
		return out.str();
	}

	std::string const & toString() const {
		return _str;
	}

	int getPrecision() const {
		return _type;
	}
	eOperandType getType() const {
		return _type;
	}

	template <typename X>
	X	getStrResult(IOperand const & rhs, char op) const {
		if (rhs.getType() == Int8 || rhs.getType() == Int16 || rhs.getType() == Int32) {
			if (op == '+')
				return getValue() + std::stoi(rhs.toString());
			else if (op == '-')
				return getValue() - std::stoi(rhs.toString());
			else if (op == '*')
				return getValue() * std::stoi(rhs.toString());
			else if (op == '/')
				return getValue() / std::stoi(rhs.toString());
			else
				return std::fmod(getValue(), std::stoi(rhs.toString()));
		}
		else if (rhs.getType() == Float) {
			if (op == '+')
				return getValue() + std::stof(rhs.toString());
			else if (op == '-')
				return getValue() - std::stof(rhs.toString());
			else if (op == '*')
				return getValue() * std::stof(rhs.toString());
			else if (op == '/')
				return getValue() / std::stof(rhs.toString());
			else
				return std::fmod(getValue(), std::stof(rhs.toString()));
		}
		else {
			if (op == '+')
				return getValue() + std::stod(rhs.toString());
			else if (op == '-')
				return getValue() - std::stod(rhs.toString());
			else if (op == '*')
				return getValue() * std::stod(rhs.toString());
			else if (op == '/')
				return getValue() / std::stod(rhs.toString());
			else
				return std::fmod(getValue(), std::stod(rhs.toString()));
		}
	}

	const IOperand	*getMax(const IOperand * other) const{
		if (this->getType() > other->getType())
			return this;
		return other;
	}

	IOperand const * operator+( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8 ||
			getMax(&rhs)->getType() == Int16 ||
			getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(getMax(&rhs)->getType(), std::to_string(getStrResult<int>(rhs, '+')));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, std::to_string(getStrResult<float>(rhs, '+')));
		else
			return _factory.createOperand(Double, std::to_string(getStrResult<double>(rhs, '+')));
	}

	IOperand const * operator-( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8 ||
			getMax(&rhs)->getType() == Int16 ||
			getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(getMax(&rhs)->getType(), std::to_string(getStrResult<int>(rhs, '-')));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, std::to_string(getStrResult<float>(rhs, '-')));
		else
			return _factory.createOperand(Double, std::to_string(getStrResult<double>(rhs, '-')));
	}
	IOperand const * operator*( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8 ||
			getMax(&rhs)->getType() == Int16 ||
			getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(getMax(&rhs)->getType(), std::to_string(getStrResult<int>(rhs, '*')));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, std::to_string(getStrResult<float>(rhs, '*')));
		else
			return _factory.createOperand(Double, std::to_string(getStrResult<double>(rhs, '*')));
	}
	IOperand const * operator/( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8 ||
			getMax(&rhs)->getType() == Int16 ||
			getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(getMax(&rhs)->getType(), std::to_string(getStrResult<int>(rhs, '/')));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, std::to_string(getStrResult<float>(rhs, '/')));
		else
			return _factory.createOperand(Double, std::to_string(getStrResult<double>(rhs, '/')));
	}
	IOperand const * operator%( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8 ||
			getMax(&rhs)->getType() == Int16 ||
			getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(getMax(&rhs)->getType(), std::to_string(getStrResult<int>(rhs, '%')));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, std::to_string(getStrResult<float>(rhs, '%')));
		else
			return _factory.createOperand(Double, std::to_string(getStrResult<double>(rhs, '%')));
	}
};

#endif //ABSTRACTVM_OPERAND_HPP
