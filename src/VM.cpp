//
// Created by Roman KYSLYY on 7/24/18.
//

#include "../inc/VM.hpp"

VM::VM() {}

VM::VM(VM const &src) {
    *this = src;
}

VM& VM::operator=(VM const &src) {
    _stack = src._stack;
    return *this;
}

VM::~VM() {}

IOperand const* VM::createOperand(eOperandType type, std::string const &value) const {
    IOperand const	*(VM::*method[])(std::string const &value) const = {
            &VM::createInt8,
            &VM::createInt16,
            &VM::createInt32,
            &VM::createFloat,
            &VM::createDouble
    };
    return ((this->*method[type])(value));
}

IOperand const* VM::createInt8(std::string const &value) const {
    return new Operand<char>(Int8, static_cast<char>(std::stoi(value)));
}

IOperand const* VM::createInt16(std::string const &value) const {
    return new Operand<short>(Int16, static_cast<short>(std::stoi(value)));
}

IOperand const* VM::createInt32(std::string const &value) const {
    return new Operand<int>(Int32, std::stoi(value));
}

IOperand const* VM::createFloat(std::string const &value) const {
    return new Operand<float>(Float, std::stof(value));
}

IOperand const* VM::createDouble(std::string const &value) const {
    return new Operand<double>(Double, std::stod(value));
}
