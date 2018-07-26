//
// Created by Roman KYSLYY on 7/26/18.
//

#ifndef ABSTRACTVM_FACTORY_HPP
#define ABSTRACTVM_FACTORY_HPP

# include "IOperand.hpp"

class Factory {
public:
	Factory();
	Factory(Factory const & src);
	Factory &operator=(Factory const & src);
	~Factory();

	IOperand const* createOperand(eOperandType type, std::string const &value) const;

	IOperand const* createInt8(std::string const &value) const;

	IOperand const* createInt16(std::string const &value) const;

	IOperand const* createInt32(std::string const &value) const;

	IOperand const* createFloat(std::string const &value) const;

	IOperand const* createDouble(std::string const &value) const;
};

#endif //ABSTRACTVM_FACTORY_HPP
