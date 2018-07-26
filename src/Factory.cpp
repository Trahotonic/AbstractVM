//
// Created by Roman KYSLYY on 7/26/18.
//

#include <climits>
#include "../inc/Factory.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Exceptions.hpp"

Factory::Factory() {}

Factory::Factory(Factory const &src) {
	*this = src;
}

Factory& Factory::operator=(Factory const &src) {
	static_cast<void>(src);
	return *this;
}

Factory::~Factory() {}

IOperand const* Factory::createOperand(eOperandType type, std::string const &value) const {
	IOperand const	*(Factory::*method[])(std::string const &value) const = {
			&Factory::createInt8,
			&Factory::createInt16,
			&Factory::createInt32,
			&Factory::createFloat,
			&Factory::createDouble
	};
	return ((this->*method[type])(value));
}

IOperand const* Factory::createInt8(std::string const &value) const {
    if (std::stol(value) > CHAR_MAX) {
		std::cout << "\e[4mLine " << line << "\e[24m : \e[31mError\e[0m : \"Int8 (\e[31m"
                                          << value << "\e[0m)\" - <Int8> ";
		throw ValueOverflow();
    }
    if (std::stol(value) < CHAR_MIN) {
		std::cout << "\e[4mLine " << line << "\e[24m : \e[31mError\e[0m : \"Int8 (\e[31m"
                                          << value << "\e[0m)\" - <Int8> ";
		throw ValueUnderflow();
    }
	return new Operand<char>(Int8, static_cast<char>(std::stoi(value)));
}

IOperand const* Factory::createInt16(std::string const &value) const {
    if (std::stol(value) > SHRT_MAX)
        throw ValueOverflow();
    if (std::stol(value) < SHRT_MIN)
        throw ValueUnderflow();
	return new Operand<short>(Int16, static_cast<short>(std::stoi(value)));
}

IOperand const* Factory::createInt32(std::string const &value) const {
	if (std::stol(value) > INT_MAX)
		throw ValueOverflow();
	if (std::stol(value) < INT_MIN)
		throw ValueUnderflow();
	return new Operand<int>(Int32, std::stoi(value));
}

IOperand const* Factory::createFloat(std::string const &value) const {
	return new Operand<float>(Float, std::stof(value));
}

IOperand const* Factory::createDouble(std::string const &value) const {
	return new Operand<double>(Double, std::stod(value));
}