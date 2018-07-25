//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_VM_HPP
#define ABSTRACTVM_VM_HPP

#include <list>
#include "Operand.hpp"

class VM {
private:
	std::list<IOperand*>    _stack;
	IOperand const *	    createInt8( std::string const & value ) const;
	IOperand const *	    createInt16( std::string const & value ) const;
	IOperand const *	    createInt32( std::string const & value ) const;
	IOperand const *	    createFloat( std::string const & value ) const;
	IOperand const *	    createDouble( std::string const & value ) const;
    std::string			    getStrSum(IOperand*, IOperand*);
    void                    add();
public:
	VM();
	VM(VM const & src);
	VM	&operator=(VM const & src);
	~VM();

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	void                    push(IOperand*);
	void                    dump();
};

#endif //ABSTRACTVM_VM_HPP
