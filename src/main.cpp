#include <iostream>
#include <stack>
#include "../inc/Operand.hpp"

int main(int argc, char **argv)
{
	argc = 0;
	argv = nullptr;
	std::stack<IOperand*> stack;
	Operand<float>	op(Int8, 300);
	stack.push(&op);
	std::cout << stack.top()->toString() << std::endl;
	Operand<int>	op2(Int32, 300);
	stack.push(&op2);
	std::cout << stack.top()->toString() << std::endl;
	return 0;
}