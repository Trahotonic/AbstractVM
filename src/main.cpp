#include <regex>
#include "../inc/VM.hpp"
#include <typeinfo>
#include <cfloat>

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
