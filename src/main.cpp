/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:08:18 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/23 15:08:19 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

int main(int argc, char **argv)
{
	VM  vm;

	try {
		vm.readInput(argc, argv);
		vm.run();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
