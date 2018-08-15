//
// Created by Roman KYSLYY on 7/26/18.
//

#include <climits>
#include <cfloat>
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
    if (value.length() > 19) {
        if (value[0] == '-') throw ValueUnderflow(line, value, "<Int8>");
        else throw ValueOverflow(line, value, "<Int8>");
    }
    if (std::stol(value) > CHAR_MAX)
        throw ValueOverflow(line, value, "<Int8>");
    if (std::stol(value) < CHAR_MIN)
        throw ValueUnderflow(line, value, "<Int8>");
	return new Operand<char>(Int8, static_cast<char>(std::stoi(value)), value);
}

IOperand const* Factory::createInt16(std::string const &value) const {
    if (value.length() > 19) {
        if (value[0] == '-') throw ValueUnderflow(line, value, "<Int8>");
        else throw ValueOverflow(line, value, "<Int8>");
    }
    if (std::stol(value) > SHRT_MAX)
	    throw ValueOverflow(line, value, "<Int16>");
    if (std::stol(value) < SHRT_MIN)
	    throw ValueUnderflow(line, value, "<Int16>");
	return new Operand<short>(Int16, static_cast<short>(std::stoi(value)), value);
}

IOperand const* Factory::createInt32(std::string const &value) const {
    if (value.length() > 19) {
        if (value[0] == '-') throw ValueUnderflow(line, value, "<Int8>");
        else throw ValueOverflow(line, value, "<Int8>");
    }
	if (std::stol(value) > INT_MAX)
		throw ValueOverflow(line, value, "<Int32>");
	if (std::stol(value) < INT_MIN)
		throw ValueUnderflow(line, value, "<Int32>");
	return new Operand<long>(Int32, std::stol(value), value);
}

IOperand const* Factory::createFloat(std::string const &value) const {
	try {
		std::stof(value);
	}
	catch (std::exception & e) {
        throw ValueOverflow(line, value, "<Float>");
	}
	return new Operand<float>(Float, std::stof(value), value);
}

IOperand const* Factory::createDouble(std::string const &value) const {
	try {
		std::stod(value);
	}
	catch (std::exception & e) {
        throw ValueOverflow(line, value, "<Double>");
	}
	return new Operand<double>(Double, std::stod(value), value);
}