#include <regex>
#include "../inc/VM.hpp"
#include <typeinfo>

int main(int argc, char **argv)
{
//    argc = 0;
//    argv = 0;
	VM  vm;

	try {
		vm.readInput(argc, argv);
		vm.run();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
//        Lexer   lexer;
//        lexer.readInput(argc, argv);
//        Parser  parser;
//        parser.setTokens(lexer.getTokens());
//        try{
//            parser.parseTokens();
//        }
//        catch (std::exception & e) {
//            std::cout << e.what() << std::endl;
//        }
    return 0;
}
