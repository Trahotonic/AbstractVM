//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_VM_HPP
#define ABSTRACTVM_VM_HPP

#include <stack>
#include "IOperand.hpp"

class VM {
private:
	std::stack<IOperand*> _stack;
};

#endif //ABSTRACTVM_VM_HPP
