//
// Created by Roman Kyslyy on 7/29/18.
//

#include "../inc/Parser.hpp"
#include "../inc/VM.hpp"

Parser::Parser() {}

Parser::Parser(VM * pVM) : _parentVM(pVM), _error(false) {}

Parser::Parser(Parser const &src) {
    *this = src;
}

Parser& Parser::operator=(Parser const &src) {
    _parentVM = src._parentVM;
    return *this;
}

Parser::~Parser() {}

void Parser::setTokens(std::vector<std::vector<Token *> > vec) {
    _tokens = vec;
}

void Parser::parseTokens() {
    for (int i = 0; i < static_cast<int>(_tokens.size()); ++i) {
        handleError(_tokens[i], i + 1);
    }
}

void Parser::handleError(std::vector<Token*> tokens, int i) {
    eTokens worst = getWorstToken(tokens);
    if (worst == OK)
        return ;
    else if (worst == UNKNOWN_INSTRUCTION) {
        if (!_error)
            _error = true;
        std::cout << "\e[4mLine " << i << "\e[24m : \e[31mError\e[0m : \"";
        printFirstRed(tokens[0]->getValue());
        throw UnknownCommand();
    }
    else if (worst == UNKNOWN_DATATYPE) {
        if (!_error)
            _error = true;
        std::cout << "\e[4mLine " << i << "\e[24m : \e[31mError\e[0m : \"";
        std::cout << tokens[0]->getValue() << " ";
        printFirstRed(tokens[1]->getValue());
        std::cout << UnknownDataType().what() << std::endl;
        if (noArgsExist(tokens)) {
            std::cout << "\e[4mLine " << i << "\e[24m : \e[31mError\e[0m : \"";
            std::cout << tokens[0]->getValue() << " " << tokens[1]->getValue() << "\" - ";
            std::cout << "Missing argument in brackets\n";
        }
    }
}

eTokens Parser::getWorstToken(std::vector<Token *> tokens) {
    for (int i = 0; i < static_cast<int>(tokens.size()); ++i) {
        if (tokens[i]->getType() == UNKNOWN_INSTRUCTION ||
                tokens[i]->getType() == UNKNOWN_DATATYPE ||
                tokens[i]->getType() == MISSING_OPENBRACKET ||
                tokens[i]->getType() == MISSING_CLOSEBRACKET ||
                tokens[i]->getType() == EMPTY_BRACKETS ||
                tokens[i]->getType() == NOARGS ||
                tokens[i]->getType() == EXCESS_SYMBOLS)
            return tokens[i]->getType();
    }
    return OK;
}

void Parser::printFirstRed(std::string line) {
    bool    red = true;
    std::cout << "\e[31m";
    for (int i = 0; i < static_cast<int>(line.length()); ++i) {
        std::cout << line[i];
        if (((isblank(line[i]) || line[i + 1] == '(') && red) || i + 1 == static_cast<int>(line.length())) {
            std::cout << "\e[0m";
            red = false;
        }
    }
    std::cout <<  "\" - ";
}

bool Parser::noArgsExist(std::vector<Token *> tokens) {
    for (int i = 0; i < static_cast<int>(tokens.size()); ++i)
        if (tokens[i]->getType() == NOARGS)
            return true;
    return false;
}