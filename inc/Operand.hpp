//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

# include "IOperand.hpp"
# include "Converter.hpp"

# include <iostream>
# include <sstream>
# include <string>

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T				_value;
	std::string		_str;
	Converter       _converter;

public:
	Operand() : _type(Int8), _value(0), _str(toString(_value)) {}
	Operand(eOperandType type, T value) : _type(type), _value(value), _str(toString(_value)) {}
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

	template <typename X>
	std::string toString(const X a_value)
	{
		std::ostringstream out;
		out << std::setprecision(2) << std::fixed << a_value;
		return out.str();
	}

	IOperand const* createOperand(eOperandType type, std::string const &value) const {
		IOperand const	*(Operand::*method[])(std::string const &value) const = {
				&Operand::createInt8,
				&Operand::createInt16,
				&Operand::createInt32,
				&Operand::createFloat,
				&Operand::createDouble
		};
		return ((this->*method[type])(value));
	}

	IOperand const* createInt8(std::string const &value) const {
		return new Operand<char>(Int8, static_cast<char>(std::stoi(value)));
	}

	IOperand const* createInt16(std::string const &value) const {
		return new Operand<short>(Int16, static_cast<short>(std::stoi(value)));
	}

	IOperand const* createInt32(std::string const &value) const {
		return new Operand<int>(Int32, std::stoi(value));
	}

	IOperand const* createFloat(std::string const &value) const {
		return new Operand<float>(Float, std::stof(value));
	}

	IOperand const* createDouble(std::string const &value) const {
		return new Operand<double>(Double, std::stod(value));
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

	const IOperand	*getMax(const IOperand * other) const{
		if (this->getType() > other->getType())
			return this;
		return other;
	}

	IOperand const * operator+( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return createOperand(Int8, _converter.getStrSum(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return createOperand(Int16, _converter.getStrSum(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return createOperand(Int32, _converter.getStrSum(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return createOperand(Float, _converter.getStrSum(this, &rhs));
		else
			return createOperand(Double, _converter.getStrSum(this, &rhs));
	}

	IOperand const * operator-( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return createOperand(Int8, _converter.getStrSub(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return createOperand(Int16, _converter.getStrSub(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return createOperand(Int32, _converter.getStrSub(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return createOperand(Float, _converter.getStrSub(this, &rhs));
		else
			return createOperand(Double, _converter.getStrSub(this, &rhs));
	}
	IOperand const * operator*( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return createOperand(Int8, _converter.getStrMul(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return createOperand(Int16, _converter.getStrMul(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return createOperand(Int32, _converter.getStrMul(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return createOperand(Float, _converter.getStrMul(this, &rhs));
		else
			return createOperand(Double, _converter.getStrMul(this, &rhs));
	}
	IOperand const * operator/( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return createOperand(Int8, _converter.getStrDiv(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return createOperand(Int16, _converter.getStrDiv(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return createOperand(Int32, _converter.getStrDiv(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return createOperand(Float, _converter.getStrDiv(this, &rhs));
		else
			return createOperand(Double, _converter.getStrDiv(this, &rhs));
	}
	IOperand const * operator%( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return createOperand(Int8, _converter.getStrMod(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return createOperand(Int16, _converter.getStrMod(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return createOperand(Int32, _converter.getStrMod(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return createOperand(Float, _converter.getStrMod(this, &rhs));
		else
			return createOperand(Double, _converter.getStrMod(this, &rhs));
	}
};

#endif //ABSTRACTVM_OPERAND_HPP
