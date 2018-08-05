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
    int             _line;
public:
    MethodData();
    MethodData(std::string, eOperandType, std::string, int);
    MethodData(std::string, int);
    MethodData(MethodData const & src);
    MethodData  &operator=(MethodData const & src);
    ~MethodData();

    std::string     getInstr();
    eOperandType    getType();
    std::string     getValue();
    int             getLine();
};

#endif //ABSTRACTVM_METHODDATA_HPP
