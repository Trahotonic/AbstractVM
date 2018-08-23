/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:07:56 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:07:57 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
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

std::vector<std::vector<Token*> > Lexer::getTokens() {
	return _tokens;
}

void Lexer::readInput(int argc, char **argv) {
	if (argc == 2) {
		if (strcmp(argv[1], "-v"))
			readFromFile(argv[1]);
		else
			readFromSTDIN();
	}
	else if (argc == 3) {
		if (!strcmp(argv[2], "-v"))
			readFromFile(argv[1]);
		else if (!strcmp(argv[1], "-v"))
			readFromFile(argv[2]);
		else {
			if (!strcmp(argv[1], "-v"))
				throw FileDoesNotExist(argv[2]);
			else if (!strcmp(argv[2], "-v"))
				throw FileDoesNotExist(argv[2]);
			else
				throw FileDoesNotExist(argv[1]);
		}
	}
	else if (argc == 1)
		readFromSTDIN();
	else
		throw InvalidArguments();
}

void Lexer::readFromFile(char *file) {
	std::ifstream   is(file);
	if (is.fail())
		throw FileDoesNotExist(file);
	std::string	 buffer;
	while (std::getline(is, buffer)) {
		analyzeLine(buffer);
	}
}

void Lexer::readFromSTDIN() {
	std::string	 buffer;
	std::regex	  eof("([\\t\\s]*;;[\\t\\s]*)");
	while (std::getline(std::cin, buffer)) {
		if (std::regex_match(buffer, eof))
			return ;
		analyzeLine(buffer);
	}
	throw UnexpectedEnd();
}

void Lexer::lexArgInstr(std::cmatch &result, std::string &buffer,
						std::vector<Token *> &list) {
	std::regex  whitespaces("([\\t\\s]*)");
	std::regex  dataType("([\\t\\s]+)(int8|int16|int32|float|double)(.*)");
	if (std::regex_match(static_cast<std::string>(result[3]), whitespaces)) {
		list.push_back(new Token(INSTRUCTION, result[2]));
		list.push_back(new Token(MISSING_DATATYPE, "!"));
	}
	else if (!isblank(static_cast<std::string>(result[3])[0])) {
		list.push_back(new Token(UNKNOWN_INSTRUCTION, buffer));
	}
	else if (std::regex_match(static_cast<std::string>(result[3]).c_str(),
							  dataType)) {
		list.push_back(new Token(INSTRUCTION, result[2]));
		buffer = result[3];
		std::regex_match(buffer.c_str(), result, dataType);
		list.push_back(new Token(DATATYPE, static_cast<std::string>(result[1]) +
				static_cast<std::string>(result[2])));
		buffer = result[3];
		lexBra(list, buffer);
	}
	else {
		list.push_back(new Token(INSTRUCTION, result[2]));
		list.push_back(new Token(UNKNOWN_DATATYPE, result[3]));
	}
}

void Lexer::lexNonArgInstr(std::cmatch &result, std::string &buffer, std::vector<Token *> &list) {
	std::regex  comment("([\\t\\s]*;.*)");
	std::regex  whitespaces("([\\t\\s]*)");
	std::regex  whitespacesTrash("([\\t\\s]+)(.+)");
	if (std::regex_match(static_cast<std::string>(result[3]).c_str(), whitespaces) ||
		std::regex_match(static_cast<std::string>(result[3]).c_str(), comment)) {
		list.push_back(new Token(INSTRUCTION, result[2]));
	}
	else if (std::regex_match(static_cast<std::string>(result[3]).c_str(), whitespacesTrash)){
		list.push_back(new Token(INSTRUCTION, result[2]));
		std::regex_match(static_cast<std::string>(result[3]).c_str(), result, whitespacesTrash);
		list.push_back(new Token(EXCESS_SYMBOLS, static_cast<std::string>(result[1]) +
				static_cast<std::string>(result[2])));
	}
	else
		list.push_back(new Token(UNKNOWN_INSTRUCTION, buffer));
}

void Lexer::analyzeLine(std::string &line) {
	std::cmatch		result;
	std::string		buffer = line;
	std::regex		argInstr("([\\t\\s]*)(push|assert)(.*)");
	std::regex		nonArgInstr("([\\t\\s]*)(add|sub|mul|div|mod|pop|dump|print|exit)(.*)");
	std::regex		dataType("([\\t\\s]+)(int8|int16|int32|float|double)(.*)");
	std::regex		brackets("(\\(.*)\\))");
	std::regex		excess("([\\t\\s]*)(.+)");
	std::regex		comment("([\\t\\s]*;.*)");
	std::vector<Token*> list;
	if (line.empty()) {
		list.push_back(new Token(EMPTY_LINE, ""));
		return _tokens.push_back(list);
	}
	if (std::regex_match(buffer.c_str(), comment))
		list.push_back(new Token(COMMENT, result[2]));
	else if (std::regex_match(buffer.c_str(), result, argInstr))
		lexArgInstr(result, buffer, list);
	else if (std::regex_match(buffer.c_str(), result, nonArgInstr))
	   lexNonArgInstr(result, buffer, list);
	else
		list.push_back(new Token(UNKNOWN_INSTRUCTION, buffer));
	_tokens.push_back(list);
}

void Lexer::lexBra(std::vector<Token*> &list, std::string const & line) {
	std::regex		valueInPar("(\\()(.+)(\\))(.*)");
	std::regex		emptyPar("(\\()(\\))(.*)");
	std::regex		openParExists("(\\()(.*)");
	std::regex		comment("([\\t\\s]*;.*)");
	std::regex		close("(.*)(\\)(.*))");
	std::cmatch		result;
	std::string		buffer;
	if (line == "")
		return list.push_back(new Token(NOARGS, "!"));
	if (std::regex_match(line.c_str(), result, valueInPar)) {
		list.push_back(new Token(OPENBRACKET, "("));
		list.push_back(new Token(VALUE, result[2]));
		list.push_back(new Token(CLOSEBRACKET, result[3]));
		buffer = result[4];
		if (buffer != "")
			if (!std::regex_match(buffer.c_str(), result, comment))
				list.push_back(new Token(EXCESS_SYMBOLS, buffer));
	}
	else if (std::regex_match(line.c_str(), result, emptyPar)) {
		list.push_back(new Token(EMPTY_BRACKETS, "()"));
		buffer = result[3];
		if (buffer != "")
			if (!std::regex_match(buffer.c_str(), result, comment))
				list.push_back(new Token(EXCESS_SYMBOLS, buffer));
	}
	else if (std::regex_match(line.c_str(), result, openParExists)) {
		list.push_back(new Token(OPENBRACKET, "("));
		list.push_back(new Token(VALUE, result[2]));
		list.push_back(new Token(MISSING_CLOSEBRACKET, "!"));
	}
	else if (!isblank(line[0])) {
		buffer = list.back()->getValue() + line;
		list.pop_back();
		list.push_back(new Token(UNKNOWN_DATATYPE, buffer));
	}
	else
		list.push_back(new Token(MISSING_OPENBRACKET, line));
}
