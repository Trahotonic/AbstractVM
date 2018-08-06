//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_OPERAND_HPP
#define ABSTRACTVM_OPERAND_HPP

# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>

# include "IOperand.hpp"
# include "Converter.hpp"
# include "Factory.hpp"

template <typename T>
class Operand : public IOperand {
private:
	eOperandType	_type;
	T				_value;
	std::string		_str;
	Converter       _converter;
	Factory         _factory;

public:
	Operand() : _type(Int8), _value(0), _str(to_string(_value)) {}
	Operand(eOperandType type, T value) : _type(type), _value(value), _str(to_string(_value)) {}
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

	const IOperand	*getMax(const IOperand * other) const{
		if (this->getType() > other->getType())
			return this;
		return other;
	}

	IOperand const * operator+( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return _factory.createOperand(Int8, _converter.getStrSum(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return _factory.createOperand(Int16, _converter.getStrSum(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(Int32, _converter.getStrSum(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, _converter.getStrSum(this, &rhs));
		else
			return _factory.createOperand(Double, _converter.getStrSum(this, &rhs));
	}

	IOperand const * operator-( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return _factory.createOperand(Int8, _converter.getStrSub(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return _factory.createOperand(Int16, _converter.getStrSub(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(Int32, _converter.getStrSub(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, _converter.getStrSub(this, &rhs));
		else
			return _factory.createOperand(Double, _converter.getStrSub(this, &rhs));
	}
	IOperand const * operator*( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return _factory.createOperand(Int8, _converter.getStrMul(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return _factory.createOperand(Int16, _converter.getStrMul(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(Int32, _converter.getStrMul(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, _converter.getStrMul(this, &rhs));
		else
			return _factory.createOperand(Double, _converter.getStrMul(this, &rhs));
	}
	IOperand const * operator/( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return _factory.createOperand(Int8, _converter.getStrDiv(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return _factory.createOperand(Int16, _converter.getStrDiv(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(Int32, _converter.getStrDiv(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, _converter.getStrDiv(this, &rhs));
		else
			return _factory.createOperand(Double, _converter.getStrDiv(this, &rhs));
	}
	IOperand const * operator%( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return _factory.createOperand(Int8, _converter.getStrMod(this, &rhs));
		else if (getMax(&rhs)->getType() == Int16)
			return _factory.createOperand(Int16, _converter.getStrMod(this, &rhs));
		else if (getMax(&rhs)->getType() == Int32)
			return _factory.createOperand(Int32, _converter.getStrMod(this, &rhs));
		else if (getMax(&rhs)->getType() == Float)
			return _factory.createOperand(Float, _converter.getStrMod(this, &rhs));
		else
			return _factory.createOperand(Double, _converter.getStrMod(this, &rhs));
	}
};

#endif //ABSTRACTVM_OPERAND_HPP
