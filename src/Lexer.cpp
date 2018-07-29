//
// Created by Roman Kyslyy on 7/28/18.
//

# include "../inc/Lexer.hpp"

Lexer::Lexer() {}

Lexer::Lexer(Lexer const &src) {
    *this = src;
}

Lexer& Lexer::operator=(Lexer const &src) {
    static_cast<void>(src);
    return *this;
}

Lexer::~Lexer() {}

void Lexer::readInput(int argc, char **argv) {
    if (argc == 2)
        readFromFile(argv[1]);
    else
        readFromSTDIN();
}

void Lexer::readFromFile(char *file) {
    std::ifstream   is(file);
    std::string     buffer;
    while (std::getline(is, buffer))
        analyzeLine(buffer);
    for (int j = 0; j < static_cast<int>(_tokens.size()); ++j) {
        for (int i = 0; i < static_cast<int>(_tokens[j].size()); ++i) {
            std::cout << *_tokens[j][i];
        }
        std::cout << std::endl;
    }
}

void Lexer::readFromSTDIN() {
    std::string     buffer;
    while (std::getline(std::cin, buffer))
        analyzeLine(buffer);
    for (int j = 0; j < static_cast<int>(_tokens.size()); ++j) {
        for (int i = 0; i < static_cast<int>(_tokens[j].size()); ++i) {
            std::cout << *_tokens[j][i];
        }
        std::cout << std::endl;
    }
}

void Lexer::analyzeLine(std::string &line) {
    std::cmatch         result;
    std::string         buffer = line;
    std::regex          command("(push|assert)( )(.*)");
    std::regex          dataType("(int8|int16|int32|float|double)(.*)");
    std::vector<Token*> list;
    if (line == "") {
        list.push_back(new Token(EMPTY_LINE, ""));
        return _tokens.push_back(list);
    }
    if (std::regex_match(buffer.c_str(), result, command)) {
        list.push_back(new Token(INSTRUCTION, result[1]));
        buffer = result[3];
        if (std::regex_match(buffer.c_str(), result, dataType)) {
            list.push_back(new Token(DATATYPE, result[1]));
            buffer = result[2];
            lexBra(list, buffer);
        }
        else
            list.push_back(new Token(UNKNOWN_DATATYPE, buffer));
    }
    else
        list.push_back(new Token(UNKNOWN_INSTRUCTION, buffer));
    _tokens.push_back(list);
}

void Lexer::lexBra(std::vector<Token*> &list, std::string const & line) {
    std::regex          valueInPar("(\\()(.+)(\\))(.*)");
    std::regex          emptyPar("(\\()(\\))(.*)");
    std::regex          openParExists("(\\()(.*)");
    std::regex          comment("( ;.*)");
    std::cmatch         result;
    std::string         buffer;
    if (line == "")
        return list.push_back(new Token(NOARGS, ""));
    if (std::regex_match(line.c_str(), result, valueInPar)) {
        list.push_back(new Token(OPENBRACKET, "("));
        list.push_back(new Token(VALUE, result[2]));
        list.push_back(new Token(CLOSEBRACKET, ")"));
        buffer = result[4];
        if (buffer != "")
            if (!std::regex_match(buffer.c_str(), result, comment))
                list.push_back(new Token(EXCESS_SYMBOLS, buffer));
    }
    else if (std::regex_match(line.c_str(), result, emptyPar)) {
        list.push_back(new Token(EMPTY_BRACKETS, ""));
        buffer = result[3];
        if (buffer != "")
            if (!std::regex_match(buffer.c_str(), result, comment))
                list.push_back(new Token(EXCESS_SYMBOLS, buffer));
    }
    else if (std::regex_match(line.c_str(), result, openParExists)) {
        list.push_back(new Token(OPENBRACKET, "("));
        list.push_back(new Token(VALUE, result[2]));
        list.push_back(new Token(MISSING_CLOSEBRACKET, ""));
    }
    else
        list.push_back(new Token(MISSING_OPENBRACKET, ""));
}
