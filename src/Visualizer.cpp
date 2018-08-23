/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Visualizer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:08:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:08:15 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Visualizer.hpp"

Visualizer::Visualizer() : _exit(false) {
}

Visualizer::Visualizer(Visualizer const &src) {
	*this = src;
}

Visualizer& Visualizer::operator=(Visualizer const &src) {
	static_cast<void>(src);
	return *this;
}

Visualizer::~Visualizer() {}

void Visualizer::initVis() {
	initscr();
	curs_set(0);
	start_color();
	use_default_colors();
	noecho();
	init_pair(1, COLOR_YELLOW, -1);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_BLUE, -1);
	init_pair(4, COLOR_CYAN, -1);
	init_pair(5, COLOR_MAGENTA, -1);
	init_pair(6, COLOR_RED, -1);
	for (int i = 1; i < 100; ++i) {
		mvwprintw(stdscr, 0, i, "-");
		mvwprintw(stdscr, 2, i, "-");
		mvwprintw(stdscr, 20, i, "-");
	}
	for (int i = 1; i < 20; ++i) {
		mvwprintw(stdscr, i, 0, "|");
		mvwprintw(stdscr, i, 34, "|");
		mvwprintw(stdscr, i, 100, "|");
	}
	for (int i = 35; i < 100; ++i)
		mvwprintw(stdscr, 4, i, "-");
	for (int i = 101; i < 104; ++i) {
		mvwprintw(stdscr, 2, i, "-");
		mvwprintw(stdscr, 4, i, "-");
	}
	mvwprintw(stdscr, 3, 104, "|");
	mvwprintw(stdscr, 1, 15, "STACK");
	mvwprintw(stdscr, 1, 61, "NEXT OPERATION");
	attron(A_DIM);
	mvwprintw(stdscr, 21, 68, "'ENTER' - continue; 'ESC' - exit");
	attroff(A_DIM);
}

void Visualizer::refreshWin() {
	for (int i = 3; i < 20; ++i) {
		for (int j = 1; j < 33; ++j) {
			mvwprintw(stdscr, i, j, " ");
		}
	}
	for (int j = 35; j < 100; ++j) {
		mvwprintw(stdscr, 3, j, " ");
	}
	for (int i = 5; i < 20; ++i) {
		for (int j = 35; j < 100; ++j) {
			mvwprintw(stdscr, i, j, " ");
		}
	}
}

void Visualizer::toggleAttr(eOperandType type, bool on) {
	if (on)
		attron(COLOR_PAIR(type + 1));
	else
		attroff(COLOR_PAIR(type + 1));
}

std::string Visualizer::_trim(std::string str, eOperandType type) {
	std::ostringstream out;
	if (type == Float)
		out << std::setprecision(2) << std::fixed << std::stof(str);
	else
		out << std::setprecision(2) << std::fixed << std::stod(str);
	return out.str();
}

void Visualizer::printFloat(const std::string &value, int n) {
	if ((value.find('.') == std::string::npos && value.length() > 23) ||
			(value.find('.') > 23)) {
		for (int i = 8, q = 0; i < 31; ++i, ++q) {
			mvwprintw(stdscr, n, i, "%c", value[q]);
		}
		mvwprintw(stdscr, n, 31, "...");
	}
	else
		mvwprintw(stdscr, n, 8, _trim(value, Double).c_str());
}

void Visualizer::dealWithLong(std::string ins, std::string buff, int len, int y) {
	if (35 + ins.length() + len + buff.length() <= 100)
		mvwprintw(stdscr, y, 35 + ins.length() + len, buff.c_str());
	else {
		for (int i = 35 + ins.length() + len, n = 0; i < 98; ++i, ++n) {
			mvwprintw(stdscr, y, i, "%c", buff[n]);
		}
		mvwprintw(stdscr, y, 97, "...");
	}
}

void Visualizer::printOps(std::vector<MethodData *> &datas, int iter,
						  std::map<eOperandType, std::string> map) {
	std::string	buffer;
	int 		len;
	attron(A_BOLD);
	mvwprintw(stdscr, 3, 35, datas[iter]->getInstr().c_str());
	attroff(A_BOLD);
	if (datas[iter]->getInstr() == "push" || datas[iter]->getInstr() == "assert") {
		toggleAttr(datas[iter]->getType(), true);
		buffer = " " + map[datas[iter]->getType()];
		mvwprintw(stdscr, 3, 35 + datas[iter]->getInstr().length(), buffer.c_str());
		toggleAttr(datas[iter]->getType(), false);
		len = buffer.length();
		buffer = "(" + datas[iter]->getValue() + ")";
		dealWithLong(datas[iter]->getInstr(), buffer, len, 3);
	}

	for (int i = iter - 1, y = 5; i >= 0; --i, ++y) {
		if (y == 19) {
			mvwprintw(stdscr, y, 35, ". . .");
			break ;
		}
		mvwprintw(stdscr, y, 35, datas[i]->getInstr().c_str());
		if (datas[i]->getInstr() == "push" || datas[i]->getInstr() == "assert") {
			buffer = " " + map[datas[i]->getType()];
			mvwprintw(stdscr, y, 35 + datas[i]->getInstr().length(), buffer.c_str());
			len = buffer.length();
			buffer = "(" + datas[i]->getValue() + ")";
			dealWithLong(datas[i]->getInstr(), buffer, len, y);
		}
	}
}

void Visualizer::endWithError() {
	int c = 0;
	for (int j = 35; j < 100; ++j) {
		mvwprintw(stdscr, 3, j, " ");
	}
	attron(COLOR_PAIR(6));
	mvwprintw(stdscr, 3, 35, "ERROR! PRESS 'ENTER' or 'ESC' FOR MORE INFO");
	attroff(COLOR_PAIR(6));
	while (c != '\n' && c != 27)
		c = getch();
	endwin();
	system("clear");
}

void Visualizer::visualize(std::list<const IOperand *> stack,
						   std::vector<MethodData*> &datas, int iter) {
	int c = 0;
	std::map<eOperandType, std::string>	typeMap =
			{{Int8, "int8"}, {Int16, "int16"}, {Int32, "int32"},
			 {Float, "float"}, {Double, "double"}};
	std::string buffer;
	int n = 3;
	refreshWin();
	for (auto it = stack.begin(); it != stack.end(); ++it) {
		toggleAttr((*it)->getType(), true);
		mvwprintw(stdscr, n, 1, typeMap[(*it)->getType()].c_str());
		toggleAttr((*it)->getType(), false);
		mvwprintw(stdscr, n, 7, " ");
		if ((*it)->getType() != Float && (*it)->getType() != Double)
			mvwprintw(stdscr, n, 8, (*it)->toString().c_str());
		else {
			if ((*it)->toString().length() <= 24)
				mvwprintw(stdscr, n, 8, _trim((*it)->toString(),
											  (*it)->getType()).c_str());
			else
				printFloat((*it)->toString(), n);
		}
		++n;
		if (n == 19) {
			mvwprintw(stdscr, n, 1, ". . .");
			break ;
		}
	}
	printOps(datas, iter, typeMap);
	while (c != '\n' && c != 27)
		c = getch();
	if (c == 27) {
		endwin();
		_exit = true;
		return ;
	}
	if (datas[iter]->getInstr() == "print") {
		if (stack.empty())
			throw EmptyStackException("Cannot print", datas[iter]->getLine());
		else
			mvwprintw(stdscr, 3, 102, "%c", std::stoi(stack.front()->toString()));
	}
}

bool Visualizer::getExit() {
	return _exit;
}
