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

	const IOperand	*getMax(const IOperand * other) const{
		if (this->getType() > other->getType())
			return this;
		return other;
	}

	IOperand const * operator+( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return new Operand<char>(getMax(&rhs)->getType(), _value + std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int16)
			return new Operand<short>(getMax(&rhs)->getType(), _value + std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int32)
			return new Operand<int>(getMax(&rhs)->getType(), _value + std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Float)
			return new Operand<float>(getMax(&rhs)->getType(), static_cast<float>(_value) + std::stof(rhs.toString()));
		else
			return new Operand<double>(getMax(&rhs)->getType(), static_cast<double>(_value) + std::stod(rhs.toString()));
	}

	IOperand const * operator-( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return new Operand<char>(getMax(&rhs)->getType(), _value - std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int16)
			return new Operand<short>(getMax(&rhs)->getType(), _value - std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int32)
			return new Operand<int>(getMax(&rhs)->getType(), _value - std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Float)
			return new Operand<float>(getMax(&rhs)->getType(), static_cast<float>(_value) - std::stof(rhs.toString()));
		else
			return new Operand<double>(getMax(&rhs)->getType(), static_cast<double>(_value) - std::stod(rhs.toString()));
	}
	IOperand const * operator*( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return new Operand<char>(getMax(&rhs)->getType(), _value * std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int16)
			return new Operand<short>(getMax(&rhs)->getType(), _value * std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int32)
			return new Operand<int>(getMax(&rhs)->getType(), _value * std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Float)
			return new Operand<float>(getMax(&rhs)->getType(), static_cast<float>(_value) * std::stof(rhs.toString()));
		else
			return new Operand<double>(getMax(&rhs)->getType(), static_cast<double>(_value) * std::stod(rhs.toString()));
	}
	IOperand const * operator/( IOperand const & rhs ) const {
		if (getMax(&rhs)->getType() == Int8)
			return new Operand<char>(getMax(&rhs)->getType(), _value / std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int16)
			return new Operand<short>(getMax(&rhs)->getType(), _value / std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Int32)
			return new Operand<int>(getMax(&rhs)->getType(), _value / std::stoi(rhs.toString()));
		else if (getMax(&rhs)->getType() == Float)
			return new Operand<float>(getMax(&rhs)->getType(), static_cast<float>(_value) / std::stof(rhs.toString()));
		else
			return new Operand<double>(getMax(&rhs)->getType(), static_cast<double>(_value) / std::stod(rhs.toString()));
	}
//	IOperand const * operator%( IOperand const & rhs ) const {
//		if (getMax(&rhs)->getType() == Int8)
//			return new Operand<char>(getMax(&rhs)->getType(), _value % std::stoi(rhs.toString()));
//		else if (getMax(&rhs)->getType() == Int16)
//			return new Operand<short>(getMax(&rhs)->getType(), _value % std::stoi(rhs.toString()));
//		else if (getMax(&rhs)->getType() == Int32)
//			return new Operand<int>(getMax(&rhs)->getType(), _value % std::stoi(rhs.toString()));
//		else
//			return nullptr;
//	}
};

#endif //ABSTRACTVM_OPERAND_HPP
