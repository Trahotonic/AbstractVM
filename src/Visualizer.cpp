//
// Created by Roman Kyslyy on 8/15/18.
//

#include "../inc/Visualizer.hpp"

Visualizer::Visualizer() {
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
}

void Visualizer::visualize(std::list<const IOperand *>, MethodData *) {
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
    mvwprintw(stdscr, 1, 15, "STACK");
    mvwprintw(stdscr, 1, 61, "NEXT OPERATION");
    getch();
}
