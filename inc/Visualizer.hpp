//
// Created by Roman Kyslyy on 8/15/18.
//

#ifndef ABSTRACTVM_VISUALIZER_HPP
#define ABSTRACTVM_VISUALIZER_HPP

#include <list>
#include <ncurses.h>
#include "IOperand.hpp"
#include "MethodData.hpp"

class Visualizer {
public:
    Visualizer();
    Visualizer(Visualizer const & src);
    Visualizer  &operator=(Visualizer const & src);
    ~Visualizer();

	void    refreshWin();
	void    toggleAttr(eOperandType, bool);
    void    initVis();
    void    visualize(std::list<const IOperand*>, MethodData*);
};

#endif //ABSTRACTVM_VISUALIZER_HPP
