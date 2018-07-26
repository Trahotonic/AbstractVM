#include "../inc/Operand.hpp"

int main(int argc, char **argv)
{
	VM  vm;
	if (argc == 2)
		vm.readInput(argv[1]);
	else
		vm.readInput(stdin);
	return 0;
}