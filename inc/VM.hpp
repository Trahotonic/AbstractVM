//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_VM_HPP
#define ABSTRACTVM_VM_HPP

#include <stack>
#include "Operand.hpp"

class VM {
private:
	std::stack<IOperand*> _stack;
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
public:
	VM();
	VM(VM const & src);
	VM	&operator=(VM const & src);
	~VM();

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

#endif //ABSTRACTVM_VM_HPP
