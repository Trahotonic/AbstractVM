//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_VM_HPP
#define ABSTRACTVM_VM_HPP

#include <list>
#include "Exceptions.hpp"
#include "Operand.hpp"

class VM {
private:
	std::list<const IOperand*>      _stack;
	Factory                         _factory;
public:
	VM();
	VM(VM const & src);
	VM	&operator=(VM const & src);
	~VM();

	void                    push(eOperandType, std::string);
	void                    dump();
	void                    add();
	void                    sub();
	void                    mul();
	void                    div();
	void                    mod();
	void                    pop();
	void                    readInput(int, char**);
};

#endif //ABSTRACTVM_VM_HPP
