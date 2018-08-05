//
// Created by Roman KYSLYY on 7/24/18.
//

#ifndef ABSTRACTVM_VM_HPP
#define ABSTRACTVM_VM_HPP

#include <list>
#include "Exceptions.hpp"
#include "Operand.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

class VM {
private:
	std::list<const IOperand*>      _stack;
	Factory                         _factory;
	Lexer							_lexer;
	Parser							_parser;
public:
	VM();
	VM(VM const & src);
	VM	&operator=(VM const & src);
	~VM();

	void                    push(eOperandType, std::string);
	void                    assertV(eOperandType, std::string, int);
	void                    dump(int);
	void                    add(int);
	void                    sub(int);
	void                    mul(int);
	void                    div(int);
	void                    mod(int);
	void                    pop(int);
	void                    readInput(int, char**);
	void					run();
};

#endif //ABSTRACTVM_VM_HPP
