//
// Created by Roman KYSLYY on 7/26/18.
//

#ifndef ABSTRACTVM_EXCEPTIONS_HPP
#define ABSTRACTVM_EXCEPTIONS_HPP

#include <exception>

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

#endif //ABSTRACTVM_EXCEPTIONS_HPP
