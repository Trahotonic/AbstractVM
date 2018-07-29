//
// Created by Roman Kyslyy on 7/29/18.
//

#ifndef ABSTRACTVM_METHODDATA_HPP
#define ABSTRACTVM_METHODDATA_HPP

# include "IOperand.hpp"

class MethodData {
    std::string     _instruction;
    eOperandType    _type;
    std::string     _value;
public:
    MethodData();
    MethodData(std::string, eOperandType, std::string);
    MethodData(MethodData const & src);
    MethodData  &operator=(MethodData const & src);
    ~MethodData();

    std::string     getInstr();
    eOperandType    getType();
    std::string     getValue();
};

#endif //ABSTRACTVM_METHODDATA_HPP
