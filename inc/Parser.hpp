//
// Created by Roman Kyslyy on 7/29/18.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

# include <vector>
# include "Token.hpp"
# include "Exceptions.hpp"
# include "MethodData.hpp"

class VM;

class Parser {
    VM *                                _parentVM;
    std::vector<std::vector<Token*> >   _tokens;
    std::vector<MethodData*>            _methodDatas;
    bool                                _error;
public:
    Parser();
    Parser(VM*);
    Parser(Parser const & src);
    Parser  &operator=(Parser const & src);
    ~Parser();

    void        setTokens(std::vector<std::vector<Token*> >);
    void        parseTokens();
    void        handleError(std::vector<Token*>, int);
    eTokens     getWorstToken(std::vector<Token*>);
    void        printFirstRed(std::string);
    void        createMethodData(std::vector<Token*>, int);
};

#endif //ABSTRACTVM_PARSER_HPP
