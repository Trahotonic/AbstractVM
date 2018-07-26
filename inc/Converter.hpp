//
// Created by Roman KYSLYY on 7/26/18.
//

#ifndef ABSTRACTVM_CONVERTER_HPP
#define ABSTRACTVM_CONVERTER_HPP

# include "IOperand.hpp"

class Converter {
public:
	Converter();
	Converter(Converter const & src);
	Converter   &operator=(Converter const & src);
	~Converter();
	std::string getStrSum(const IOperand * one, const IOperand * two) const;
	std::string getStrSub(const IOperand * one, const IOperand * two) const;
	std::string getStrMul(const IOperand * one, const IOperand * two) const;
	std::string getStrDiv(const IOperand * one, const IOperand * two) const;
	std::string getStrMod(const IOperand * one, const IOperand * two) const;

};

#endif //ABSTRACTVM_CONVERTER_HPP
