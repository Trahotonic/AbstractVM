#include <regex>
#include "../inc/VM.hpp"
#include <typeinfo>

int main(int argc, char **argv)
{
	VM  vm;

	try {
		vm.readInput(argc, argv);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	vm.dump();
	return 0;
}