/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MethodData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:04:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:04:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODDATA_HPP
#define METHODDATA_HPP

# include "IOperand.hpp"

class MethodData {
	std::string		_instruction;
	eOperandType	_type;
	std::string		_value;
	int				_line;
public:
	MethodData();
	MethodData(std::string, eOperandType, std::string, int);
	MethodData(std::string, int);
	MethodData(MethodData const & src);
	MethodData  &operator=(MethodData const & src);
	~MethodData();

	std::string	 getInstr();
	eOperandType	getType();
	std::string	 getValue();
	int			 getLine();
};

#endif
