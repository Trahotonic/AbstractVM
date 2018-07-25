#include <iostream>
#include <stack>
#include "../inc/Operand.hpp"
#include <typeinfo>
#include "../inc/VM.hpp"

int main(int argc, char **argv)
{
	argc = 0;
	argv = nullptr;
	VM  vm;
	vm.push(new Operand<int>(Int32, 42));
	vm.push(new Operand<float>(Float, 80));
	vm.dump();
	return 0;
}