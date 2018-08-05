//
// Created by Roman Kyslyy on 7/29/18.
//

#include "../inc/MethodData.hpp"

MethodData::MethodData() {}

MethodData::MethodData(MethodData const &src) {
    *this = src;
}

MethodData::MethodData(std::string instr, eOperandType type, std::string value, int n) :
        _instruction(instr),
        _type(type),
        _value(value),
        _line(n)
{}

MethodData::MethodData(std::string instr, int n) :
        _instruction(instr),
        _line(n)
{}

MethodData& MethodData::operator=(MethodData const &src) {
    _instruction = src._instruction;
    _type = src._type;
    _value = src._value;
    return *this;
}

std::string MethodData::getInstr() {
    return _instruction;
}

eOperandType MethodData::getType() {
    return _type;
}

std::string MethodData::getValue() {
    return _value;
}

int MethodData::getLine() {
    return _line;
}
