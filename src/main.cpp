#include <regex>
#include "../inc/Operand.hpp"

int main(int argc, char **argv)
{
	VM  vm;

	argc = 0;
	argv = 0;
	try {
		vm.readInput(argc, argv);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}