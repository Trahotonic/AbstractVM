#ifndef TOKEN_HPP
#define TOKEN_HPP

# include <iostream>
# include <map>

typedef enum eTokens {  INSTRUCTION = 0,
						DATATYPE,
						OPENBRACKET,
						CLOSEBRACKET,
						VALUE,
						UNKNOWN_INSTRUCTION,
						UNKNOWN_DATATYPE,
						MISSING_OPENBRACKET,
						MISSING_CLOSEBRACKET,
						EMPTY_BRACKETS,
						NOARGS,
						EXCESS_SYMBOLS,
						EMPTY_LINE,
						MISSING_DATATYPE,
						COMMENT,
						GOOD}
						eTokens;

class Token {
private:
	eTokens		_type;
	std::string _value;
public:
	Token();
	Token(eTokens type, std::string const & str);
	Token(Token const & src);
	Token   &operator=(Token const & src);
	~Token();

	eTokens	 getType() const;
	std::string getValue() const;
	std::string getValueTrim() const;
};

std::ostream	&operator<<(std::ostream & o, Token const & src);

#endif
