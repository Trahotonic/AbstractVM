//
// Created by Roman KYSLYY on 7/26/18.
//

#ifndef ABSTRACTVM_EXCEPTIONS_HPP
#define ABSTRACTVM_EXCEPTIONS_HPP

#include <exception>
#include "IOperand.hpp"

class EmptyStackException : public virtual std::exception
{
public:
	EmptyStackException(void);
	EmptyStackException(EmptyStackException const & src);

	EmptyStackException	&operator=(EmptyStackException const & src);

	~EmptyStackException(void) throw();

	virtual const char* what() const throw();
};

class TooFewOperandsException : public virtual std::exception
{
public:
	TooFewOperandsException(void);
	TooFewOperandsException(TooFewOperandsException const & src);

	TooFewOperandsException	&operator=(TooFewOperandsException const & src);

	~TooFewOperandsException(void) throw();

	virtual const char* what() const throw();
};

class FloatIntoIntException : public virtual std::exception
{
public:
	FloatIntoIntException(void);
	FloatIntoIntException(FloatIntoIntException const & src);

	FloatIntoIntException	&operator=(FloatIntoIntException const & src);

	~FloatIntoIntException(void) throw();

	virtual const char* what() const throw();
};

class InvalidInput : public virtual std::exception
{
public:
	InvalidInput(void);
	InvalidInput(InvalidInput const & src);

	InvalidInput	&operator=(InvalidInput const & src);

	~InvalidInput(void) throw();

	virtual const char* what() const throw();
};

class UnknownCommand : public virtual std::exception
{
public:
	UnknownCommand(void);
	UnknownCommand(UnknownCommand const & src);

	UnknownCommand	&operator=(UnknownCommand const & src);

	~UnknownCommand(void) throw();

	virtual const char* what() const throw();
};

class ValueOverflow : public virtual std::exception
{
public:
	ValueOverflow(void);
	ValueOverflow(ValueOverflow const & src);

	ValueOverflow	&operator=(ValueOverflow const & src);

	~ValueOverflow(void) throw();

	virtual const char* what() const throw();
};

class ValueUnderflow : public virtual std::exception
{
public:
	ValueUnderflow(void);
	ValueUnderflow(ValueUnderflow const & src);

	ValueUnderflow	&operator=(ValueUnderflow const & src);

	~ValueUnderflow(void) throw();

	virtual const char* what() const throw();
};

class DivisionByZero : public virtual std::exception
{
public:
	DivisionByZero(void);
	DivisionByZero(DivisionByZero const & src);

	DivisionByZero	&operator=(DivisionByZero const & src);

	~DivisionByZero(void) throw();

	virtual const char* what() const throw();

	static void	checkZero(int c, const IOperand * one, const IOperand * two, char op);
};

class NoExit : public virtual std::exception
{
public:
	NoExit(void);
	NoExit(NoExit const & src);

	NoExit	&operator=(NoExit const & src);

	~NoExit(void) throw();

	virtual const char* what() const throw();
};

class AssertFalse : public virtual std::exception
{
public:
	AssertFalse(void);
	AssertFalse(AssertFalse const & src);

	AssertFalse	&operator=(AssertFalse const & src);

	~AssertFalse(void) throw();

	virtual const char* what() const throw();
};

#endif //ABSTRACTVM_EXCEPTIONS_HPP
