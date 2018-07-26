//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_VM_HPP
#define ABSTRACTVM_VM_HPP

#include <list>
#include <iomanip>
#include "IOperand.hpp"

class VM {
private:
	std::list<const IOperand*>      _stack;
    std::string			            getStrSum(const IOperand*, const IOperand*);
public:
	VM();
	VM(VM const & src);
	VM	&operator=(VM const & src);
	~VM();

	void                    push(const IOperand*);
	void                    dump();
	void                    add();
	void                    sub();
	void                    mul();
	void                    div();
	void                    mod();
};

#endif //ABSTRACTVM_VM_HPP
