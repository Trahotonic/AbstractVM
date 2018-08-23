/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Visualizer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:04:25 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:04:26 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <list>
#include <ncurses.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include "IOperand.hpp"
#include "MethodData.hpp"
#include "Exceptions.hpp"

class Visualizer {
private:
	bool	_exit;
public:
	Visualizer();
	Visualizer(Visualizer const & src);
	Visualizer  &operator=(Visualizer const & src);
	~Visualizer();

	std::string _trim(std::string, eOperandType);
	void		printFloat(const std::string & value, int n);
	void		refreshWin();
	void		toggleAttr(eOperandType, bool);
	void		initVis();
	void		dealWithLong(std::string, std::string, int, int);
	void		printOps(std::vector<MethodData*>&, int, std::map<eOperandType,std::string>);
	void		visualize(std::list<const IOperand*>, std::vector<MethodData*>&, int);
	void		endWithError();
	bool		getExit();
};

#endif
