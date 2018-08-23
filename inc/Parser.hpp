#ifndef PARSER_HPP
#define PARSER_HPP

# include <list>
# include <sstream>
# include "Token.hpp"
# include "Exceptions.hpp"
# include "MethodData.hpp"

class VM;

class Parser {
	VM *								_parentVM;
	std::vector<std::vector<Token*> >   _tokens;
	std::vector<MethodData*>				_methodDatas;
	bool								_error;
	bool								_exit;
	void								handleError(std::vector<Token*>, int);
	eTokens							 getWorstToken(std::vector<Token*>);
	void								createMethodData(std::vector<Token*>, int);
public:
	Parser();
	Parser(Parser const & src);
	Parser  &operator=(Parser const & src);
	~Parser();

	void						setTokens(std::vector<std::vector<Token*> >);
	void						parseTokens();
	std::vector<MethodData*>	getMethodDatas();
};

#endif
