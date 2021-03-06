/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:04:22 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:04:23 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
#define VM_HPP

#include <list>
#include "Exceptions.hpp"
#include "Operand.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Visualizer.hpp"

class VM {
private:
	std::list<const IOperand*>  _stack;
	Factory					 _factory;
	Lexer						_lexer;
	Parser						_parser;
	Visualizer					_visualizer;
	bool						_visualization;
	void						_push(eOperandType, std::string);
	void						_assertV(eOperandType, std::string, int);
	void						_dump(int);
	void						_add(int);
	void						_sub(int);
	void						_mul(int);
	void						_div(int);
	void						_mod(int);
	void						_pop(int);
	void						_print(int);
	std::string				 _trim(std::string, eOperandType);
	void						_checkAssertionOverflow(eOperandType,
														std::string, int ,
														std::map<eOperandType,
																std::string> &);
public:
	VM();
	VM(VM const & src);
	VM	&operator=(VM const & src);
	~VM();

	void					readInput(int, char**);
	void					run();
};

#endif
