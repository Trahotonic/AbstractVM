#include <regex>
#include "../inc/VM.hpp"
#include <typeinfo>

int main(int argc, char **argv)
{
//    argc = 0;
//    argv = 0;
//	VM  vm;
//
//	try {
//		vm.readInput(argc, argv);
//	}
//	catch (std::exception & e) {
//		std::cout << e.what() << std::endl;
//		return 1;
//	}
//    std::cmatch result;
//    std::string buffer = "()";
//    std::regex  command("(push )(.*)");
//    std::regex          valueInPar("(\\()(.*)(\\))(.*)");
//    std::regex          openParExists("(\\()(.*)");
//    std::regex  dataType("(int8|int16|int32)(.*)");
//    std::regex  openPar("(\\()(.*)");
//    std::regex  value("([0-9][\\.]?[0-9])(.*)");
//    std::regex  closePar("(\\))(.*)");
//    if (std::regex_match(buffer.c_str(), result, command)) {
//        buffer = result[2];
//        if (std::regex_match(buffer.c_str(), result, dataType)) {
//            buffer = result[2];
//            if (std::regex_match(buffer.c_str(), result, openPar)) {
//                buffer = result[2];
//                if (std::regex_match(buffer.c_str(), result, value)) {
//                    std::cout << result[1] << std::endl;
//                    buffer = result[2];
//                    if (std::regex_match(buffer.c_str(), result, closePar)) {
//                        std::cout << result[1] << std::endl;
//                    }
//                }
//            }
//        }
//    }
//    else {
//
//    }
        Lexer   lexer;
        lexer.readInput(argc, argv);
        Parser  parser;
        parser.setTokens(lexer.getTokens());
        try{
            parser.parseTokens();
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    return 0;
}
