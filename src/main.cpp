#include "../inc/Operand.hpp"

int main(int argc, char **argv)
{
	argc = 0;
	argv = nullptr;
	VM  vm;
	vm.push(new Operand<int>(Int32, 42));
	vm.push(new Operand<float>(Float, 80));
	vm.add();
//	vm.dump();
	vm.push(new Operand<float>(Float, 300.5));
	vm.dump();
	vm.sub();
	vm.dump();
	return 0;
}