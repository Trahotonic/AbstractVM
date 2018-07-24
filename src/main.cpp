#include <iostream>
#include <stack>
#include "../inc/Operand.hpp"
#include <typeinfo>

int main(int argc, char **argv)
{
	argc = 0;
	argv = nullptr;
	IOperand const *one = new Operand<int>(Int32, 10);
 	IOperand const *two = new Operand<double>(Double, 30);
 	IOperand const *three = *one / *two;
 	std::cout << three->toString() << std::endl;
	return 0;
}