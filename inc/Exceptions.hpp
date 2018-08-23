/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:03:40 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:03:44 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <vector>
#include <sstream>
#include "IOperand.hpp"
#include "Token.hpp"

class EmptyStackException : public virtual std::exception
{
	std::string _str;
	int 		_line;
public:
	EmptyStackException(void);
	EmptyStackException(EmptyStackException const & src);
	EmptyStackException(std::string, int);

	EmptyStackException	&operator=(EmptyStackException const & src);

	~EmptyStackException(void) throw();

	virtual const char* what() const throw();
};

class TooFewOperandsException : public virtual std::exception
{
	std::string _str;
	int		 _line;
public:
	TooFewOperandsException(void);
	TooFewOperandsException(TooFewOperandsException const & src);
	TooFewOperandsException(std::string, int);

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
	std::vector<Token*> _tokens;
	int				 _line;
public:
	InvalidInput(void);
	InvalidInput(InvalidInput const & src);
	InvalidInput(std::vector<Token*> tokens, int line);

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
	int		 _line;
	std::string _value;
	std::string _type;
public:
	ValueOverflow(void);
	ValueOverflow(ValueOverflow const & src);
	ValueOverflow(int, std::string, std::string);

	ValueOverflow	&operator=(ValueOverflow const & src);

	~ValueOverflow(void) throw();

	virtual const char* what() const throw();
};

class ValueUnderflow : public virtual std::exception
{
	int		 _line;
	std::string _value;
	std::string _type;
public:
	ValueUnderflow(void);
	ValueUnderflow(ValueUnderflow const & src);
	ValueUnderflow(int, std::string, std::string);

	ValueUnderflow	&operator=(ValueUnderflow const & src);

	~ValueUnderflow(void) throw();

	virtual const char* what() const throw();
};

class DivisionByZero : public virtual std::exception
{
	int 		_line;
	std::string	_value1;
	std::string	_value2;
	char 		_op;
public:
	DivisionByZero(void);
	DivisionByZero(DivisionByZero const & src);
	DivisionByZero(int line, std::string const & value1, std::string const & value2, char op);

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
	std::string						 _type1;
	std::string						 _type2;
	std::string						 _value1;
	std::string						 _value2;
	int								 _line;
	std::map<eOperandType, std::string> _types;
public:
	AssertFalse(void);
	AssertFalse(AssertFalse const & src);
	AssertFalse(std::string, std::string, std::string, std::string, int, std::map<eOperandType, std::string>);

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
	std::vector<Token*> _tokens;
public:
	EmptyBrackets(void);
	EmptyBrackets(EmptyBrackets const & src);
	EmptyBrackets(std::vector<Token*> tokens);

	EmptyBrackets	&operator=(EmptyBrackets const & src);

	~EmptyBrackets(void) throw();

	virtual const char* what() const throw();
};

class NoArgs : public virtual std::exception
{
	std::vector<Token*> _tokens;
public:
	NoArgs(void);
	NoArgs(NoArgs const & src);
	NoArgs(std::vector<Token*> tokens);

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
	std::vector<Token*> _tokens;
public:
	MissingDataType(void);
	MissingDataType(MissingDataType const & src);
	MissingDataType(std::vector<Token*> tokens);

	MissingDataType	&operator=(MissingDataType const & src);

	~MissingDataType(void) throw();

	virtual const char* what() const throw();
};

class NonASCII : public virtual std::exception
{
	int		 _line;
	std::string _value;
public:
	NonASCII(void);
	NonASCII(NonASCII const & src);
	NonASCII(int line, std::string const & value);

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

class FileDoesNotExist : public virtual std::exception
{
	std::string _fileName;
public:
	FileDoesNotExist(void);
	FileDoesNotExist(FileDoesNotExist const & src);
	FileDoesNotExist(std::string fileName);

	FileDoesNotExist	&operator=(FileDoesNotExist const & src);

	~FileDoesNotExist(void) throw();

	virtual const char* what() const throw();
};

class InvalidArguments : public virtual std::exception
{
public:
	InvalidArguments(void);
	InvalidArguments(InvalidArguments const & src);

	InvalidArguments	&operator=(InvalidArguments const & src);

	~InvalidArguments(void) throw();

	virtual const char* what() const throw();
};

#endif
