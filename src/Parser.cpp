//
// Created by Roman Kyslyy on 7/29/18.
//

#include "../inc/Parser.hpp"
#include "../inc/VM.hpp"

Parser::Parser() {}

Parser::Parser(VM * pVM) : _parentVM(pVM), _error(false), _exit(false) {}

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
        try {
            handleError(_tokens[i], i + 1);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    if (_error)
        throw ParsingError();
//    for (int j = 0; j < (int)_methodDatas.size(); ++j) {
//        std::cout << _methodDatas[j]->getInstr() << " " << _methodDatas[j]->getType() << " " << _methodDatas[j]->getValue() << _methodDatas[j]->getLine() << std::endl;
//    }
}

void Parser::handleError(std::vector<Token*> tokens, int i) {
	std::string message;
	if (!_exit)
		message = "\e[31mError\e[0m";
	else
		message = "\e[95mWarning\e[0m";
    eTokens worst = getWorstToken(tokens);
    if (worst == OK)
        createMethodData(tokens, i);
    else if (worst == UNKNOWN_INSTRUCTION) {
        if (!_error && !_exit)
            _error = true;
        std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        printFirstRed(tokens[0]->getValue());
        throw UnknownCommand();
    }
    else if (worst == UNKNOWN_DATATYPE) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        std::cout << tokens[0]->getValue();
        printFirstRed(tokens[1]->getValue());
        throw UnknownDataType();
    }
    else if (worst == MISSING_OPENBRACKET) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        std::cout << tokens[0]->getValue();
        std::cout << tokens[1]->getValue();
	    std::cout << "\e[31m!\e[0m" << tokens[2]->getValue() << " - ";
//        printFirstRed(tokens[2]->getValue());
        throw NoOpenBracket();
    }
    else if (worst == MISSING_CLOSEBRACKET) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        std::cout << tokens[0]->getValue();
        std::cout << tokens[1]->getValue();
        std::cout << tokens[2]->getValue();
        std::cout << tokens[3]->getValue();
        printFirstRed(tokens[4]->getValue());
        throw NoCloseBracket();
    }
    else if (worst == EMPTY_BRACKETS) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        std::cout << tokens[0]->getValue();
        std::cout << tokens[1]->getValue();
        printFirstRed(tokens[2]->getValue());
        throw EmptyBrackets();
    }
    else if (worst == NOARGS) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        std::cout << tokens[0]->getValue() << " ";
        std::cout << tokens[1]->getValue();
        printFirstRed(tokens[2]->getValue());
        throw NoArgs();
    }
    else if (worst == EXCESS_SYMBOLS) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        if (tokens[0]->getValue() == "push" || tokens[0]->getValue() == "assert") {
            std::cout << tokens[0]->getValue() << " ";
            std::cout << tokens[1]->getValue();
            std::cout << tokens[2]->getValue();
            std::cout << tokens[3]->getValue();
            std::cout << tokens[4]->getValue();
            std::cout << "\e[31m";
            std::cout << tokens[5]->getValue();
        }
        else {
            std::cout << tokens[0]->getValue() << "\e[31m";
            std::cout << tokens[1]->getValue();
        }
        std::cout << "\e[0m\" - ";
        throw Excess();
    }
    else if (worst == MISSING_DATATYPE) {
        if (!_error && !_exit)
            _error = true;
	    std::cout << "\e[4mLine " << i << "\e[24m : " << message << " : \"";
        std::cout << tokens[0]->getValue() << " \e[31m";
        std::cout << tokens[1]->getValue() ;
        std::cout << "\e[0m\" - ";
        throw MissingDataType();
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
                tokens[i]->getType() == EXCESS_SYMBOLS ||
                tokens[i]->getType() == MISSING_DATATYPE)
            return tokens[i]->getType();
    }
    return OK;
}

void Parser::printFirstRed(std::string line) {
    size_t i = 0;
    while (isblank(line[i]))
        std::cout << line[i++];
    std::cout << "\e[31m";
    while (i < static_cast<size_t>(line.size())) {
        std::cout << line[i++];
        if (i >= static_cast<size_t>(line.size()) || isblank(line[i]) || line[i] == '(') {
            std::cout << "\e[0m";
        }
    }
    std::cout <<  "\" - ";
}

void Parser::createMethodData(std::vector<Token *> tokens, int n) {
    std::regex  i("(\\-?[0-9]+)");
    std::regex  f("(-?[0-9]+[\\.]?[0-9]+)");

    std::map<std::string, eOperandType>	typeMap =
            {{"int8", Int8},
             {"int16", Int16},
             {"int32", Int32},
             {"float", Float},
             {"double", Double}};
    if (tokens[0]->getValue() == "push" || tokens[0]->getValue() == "assert")
        if (typeMap[tokens[1]->getValueTrim()] == Int8 ||
            typeMap[tokens[1]->getValueTrim()] == Int16 ||
            typeMap[tokens[1]->getValueTrim()] == Int32)
            if (!std::regex_match(tokens[3]->getValueTrim(), i)) {
	            std::cout << "\e[4mLine " << n << "\e[24m : \e[31mError\e[0m : \"";
	            std::cout << tokens[0]->getValueTrim() << " " << tokens[1]->getValueTrim() << tokens[2]->getValueTrim()
	                      << "\e[31m" << tokens[3]->getValueTrim() << "\e[0m" << tokens[4]->getValueTrim() << "\" - ";
                throw InvalidInput();
            }
    if (tokens[0]->getValueTrim() == "push" || tokens[0]->getValueTrim() == "assert") {
        _methodDatas.push_back(new MethodData(tokens[0]->getValueTrim(),
                                              typeMap[tokens[1]->getValueTrim()],
                                              tokens[3]->getValueTrim(), n));
    }
    else
        _methodDatas.push_back(new MethodData(tokens[0]->getValueTrim(), n));
		if (tokens[0]->getValueTrim() == "exit") {
			if (!_exit)
                _exit = true;
			else
				std::cout << "\e[4mLine " << n << "\e[24m : \e[97mNote\e[0m : \"\e[34mexit\e[0m\" command is redundant\n";
        }
}

std::vector<MethodData*> Parser::getMethodDatas() {
    return _methodDatas;
}