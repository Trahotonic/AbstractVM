#ifndef LEXER_HPP
#define LEXER_HPP

# include <regex>
# include <fstream>
# include <list>
# include "Exceptions.hpp"
# include "Token.hpp"

class Lexer {
	std::vector<std::vector<Token*> >   _tokens;

	void								readFromFile(char * file);
	void								readFromSTDIN();
	void								analyzeLine(std::string & line);
	void								lexArgInstr(std::cmatch & result, std::string & buffer,std::vector<Token*> & list);
	void								lexNonArgInstr(std::cmatch & result, std::string & buffer,std::vector<Token*> & list);
	void								lexBra(std::vector<Token*> & list, std::string const & line);
public:
	Lexer();
	Lexer(Lexer const & src);
	Lexer   &operator=(Lexer const & src);
	~Lexer();

	void								readInput(int argc, char ** argv);
	std::vector<std::vector<Token*> >   getTokens();
};


#endif
