//
// Created by Roman KYSLYY on 7/26/18.
//

#ifndef ABSTRACTVM_EXCEPTIONS_HPP
#define ABSTRACTVM_EXCEPTIONS_HPP

#include <exception>
#include <vector>
#include "IOperand.hpp"
#include "Token.hpp"

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
    std::vector<Token*> _tokens;
public:
	UnknownCommand(void);
	UnknownCommand(std::vector<Token*> tokens);
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

class UnknownDataType : public virtual std::exception
{
    std::vector<Token*> _tokens;
public:
	UnknownDataType(void);
	UnknownDataType(UnknownDataType const & src);
	UnknownDataType(std::vector<Token*>);

	UnknownDataType	&operator=(UnknownDataType const & src);

	~UnknownDataType(void) throw();

	virtual const char* what() const throw();
};

class NoOpenBracket : public virtual std::exception
{
    std::vector<Token*> _tokens;
public:
	NoOpenBracket(void);
	NoOpenBracket(NoOpenBracket const & src);
	NoOpenBracket(std::vector<Token*> tokens);

	NoOpenBracket	&operator=(NoOpenBracket const & src);

	~NoOpenBracket(void) throw();

	virtual const char* what() const throw();
};

class NoCloseBracket : public virtual std::exception
{
    std::vector<Token*> _tokens;
public:
    NoCloseBracket(void);
    NoCloseBracket(NoCloseBracket const & src);
    NoCloseBracket(std::vector<Token*> tokens);

    NoCloseBracket	&operator=(NoCloseBracket const & src);

    ~NoCloseBracket(void) throw();

    virtual const char* what() const throw();
};

class EmptyBrackets : public virtual std::exception
{
public:
    EmptyBrackets(void);
    EmptyBrackets(EmptyBrackets const & src);

    EmptyBrackets	&operator=(EmptyBrackets const & src);

    ~EmptyBrackets(void) throw();

    virtual const char* what() const throw();
};

class NoArgs : public virtual std::exception
{
public:
    NoArgs(void);
    NoArgs(NoArgs const & src);

    NoArgs	&operator=(NoArgs const & src);

    ~NoArgs(void) throw();

    virtual const char* what() const throw();
};

class Excess : public virtual std::exception
{
	std::vector<Token*> _tokens;
public:
    Excess(void);
    Excess(std::vector<Token*> tokens);
    Excess(Excess const & src);

    Excess	&operator=(Excess const & src);

    ~Excess(void) throw();

    virtual const char* what() const throw();
};

class MissingDataType : public virtual std::exception
{
public:
	MissingDataType(void);
	MissingDataType(MissingDataType const & src);

	MissingDataType	&operator=(MissingDataType const & src);

	~MissingDataType(void) throw();

	virtual const char* what() const throw();
};

class NonASCII : public virtual std::exception
{
public:
	NonASCII(void);
	NonASCII(NonASCII const & src);

	NonASCII	&operator=(NonASCII const & src);

	~NonASCII(void) throw();

	virtual const char* what() const throw();
};

class ParsingError : public virtual std::exception
{
public:
	ParsingError(void);
	ParsingError(ParsingError const & src);

	ParsingError	&operator=(ParsingError const & src);

	~ParsingError(void) throw();

	virtual const char* what() const throw();
};

class MissingExit : public virtual std::exception
{
public:
	MissingExit(void);
	MissingExit(MissingExit const & src);

	MissingExit	&operator=(MissingExit const & src);

	~MissingExit(void) throw();

	virtual const char* what() const throw();
};

class UnexpectedEnd : public virtual std::exception
{
public:
	UnexpectedEnd(void);
	UnexpectedEnd(UnexpectedEnd const & src);

	UnexpectedEnd	&operator=(UnexpectedEnd const & src);

	~UnexpectedEnd(void) throw();

	virtual const char* what() const throw();
};

#endif //ABSTRACTVM_EXCEPTIONS_HPP
