//
// Created by Roman Kyslyy on 8/15/18.
//

#ifndef ABSTRACTVM_VISUALIZER_HPP
#define ABSTRACTVM_VISUALIZER_HPP

#include <list>
#include <ncurses.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include "IOperand.hpp"
#include "MethodData.hpp"

class Visualizer {
public:
    Visualizer();
    Visualizer(Visualizer const & src);
    Visualizer  &operator=(Visualizer const & src);
    ~Visualizer();

	std::string _trim(std::string, eOperandType);
	void        printFloat(const std::string & value, int n);
	void        refreshWin();
	void        toggleAttr(eOperandType, bool);
    void        initVis();
    void		printOps(std::vector<MethodData*>&, int, std::map<eOperandType, std::string>);
    void        visualize(std::list<const IOperand*>, std::vector<MethodData*>&, int);
    void		endWithError();
};

#endif //ABSTRACTVM_VISUALIZER_HPP
