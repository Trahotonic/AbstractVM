//
// Created by Roman KYSLYY on 7/26/18.
//

#include <cmath>
#include "../inc/Converter.hpp"

Converter::Converter() {}

Converter::Converter(Converter const &src) {
	*this = src;
}

Converter& Converter::operator=(Converter const &src) {
	static_cast<void>(src);
	return *this;
}

Converter::~Converter() {}

std::string Converter::getStrSum(const IOperand * one, const IOperand * two) const{
	int max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	if (max == Int8)
		return std::to_string(std::stoi(one->toString()) +
                                                       std::stoi(two->toString()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->toString()) +
		                             std::stoi(two->toString())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->toString()) +
		                      std::stoi(two->toString()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->toString()) +
			                      std::stof(two->toString()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->toString()) +
			                      std::stoi(two->toString()));
		else
			return std::to_string(std::stof(one->toString()) +
			                      std::stof(two->toString()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->toString()) +
				                      std::stoi(two->toString()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->toString()) +
				                      std::stof(two->toString()));
			else
				return std::to_string(std::stod(one->toString()) +
				                      std::stod(two->toString()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->toString()) +
				                      std::stoi(one->toString()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->toString()) +
				                      std::stof(one->toString()));
			else
				return std::to_string(std::stod(two->toString()) +
				                      std::stod(one->toString()));
		}
	}
}

std::string Converter::getStrSub(const IOperand * one, const IOperand * two) const{
	int max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	if (max == Int8)
		return std::to_string(std::stoi(one->toString()) -
		                             std::stoi(two->toString()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->toString()) -
		                             std::stoi(two->toString())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->toString()) -
		                      std::stoi(two->toString()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->toString()) -
			                      std::stof(two->toString()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->toString()) -
			                      std::stoi(two->toString()));
		else
			return std::to_string(std::stof(one->toString()) -
			                      std::stof(two->toString()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->toString()) -
				                      std::stoi(two->toString()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->toString()) -
				                      std::stof(two->toString()));
			else
				return std::to_string(std::stod(one->toString()) -
				                      std::stod(two->toString()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->toString()) -
				                      std::stoi(one->toString()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->toString()) -
				                      std::stof(one->toString()));
			else
				return std::to_string(std::stod(two->toString()) -
				                      std::stod(one->toString()));
		}
	}
}

std::string Converter::getStrMul(const IOperand * one, const IOperand * two) const{
	int max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	if (max == Int8)
		return std::to_string(std::stoi(one->toString()) *
		                             std::stoi(two->toString()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->toString()) *
		                             std::stoi(two->toString())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->toString()) *
		                      std::stoi(two->toString()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->toString()) *
			                      std::stof(two->toString()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->toString()) *
			                      std::stoi(two->toString()));
		else
			return std::to_string(std::stof(one->toString()) *
			                      std::stof(two->toString()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->toString()) *
				                      std::stoi(two->toString()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->toString()) *
				                      std::stof(two->toString()));
			else
				return std::to_string(std::stod(one->toString()) *
				                      std::stod(two->toString()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->toString()) *
				                      std::stoi(one->toString()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->toString()) *
				                      std::stof(one->toString()));
			else
				return std::to_string(std::stod(two->toString()) *
				                      std::stod(one->toString()));
		}
	}
}

std::string Converter::getStrDiv(const IOperand * one, const IOperand * two) const{
	int max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	if (max == Int8)
		return std::to_string(std::stoi(one->toString()) /
		                             std::stoi(two->toString()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->toString()) /
		                             std::stoi(two->toString())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->toString()) /
		                      std::stoi(two->toString()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->toString()) /
			                      std::stof(two->toString()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->toString()) /
			                      std::stoi(two->toString()));
		else
			return std::to_string(std::stof(one->toString()) /
			                      std::stof(two->toString()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->toString()) /
				                      std::stoi(two->toString()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->toString()) /
				                      std::stof(two->toString()));
			else
				return std::to_string(std::stod(one->toString()) /
				                      std::stod(two->toString()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->toString()) /
				                      std::stoi(one->toString()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->toString()) /
				                      std::stof(one->toString()));
			else
				return std::to_string(std::stod(two->toString()) /
				                      std::stod(one->toString()));
		}
	}
}

std::string Converter::getStrMod(const IOperand * one, const IOperand * two) const{
	int max;

	if (one->getType() > two->getType())
		max = one->getType();
	else
		max = two->getType();
	if (max == Int8)
		return std::to_string(std::stoi(one->toString()) %
		                             std::stoi(two->toString()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->toString()) %
		                             std::stoi(two->toString())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->toString()) %
		                      std::stoi(two->toString()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(fmod(std::stoi(one->toString()),
			                           std::stof(two->toString())));
		else if (two->getType() != Float)
			return std::to_string(fmod(std::stof(one->toString()),
			                           std::stoi(two->toString())));
		else
			return std::to_string(fmod(std::stof(one->toString()),
			                           std::stof(two->toString())));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(fmod(std::stod(one->toString()),
				                           std::stoi(two->toString())));
			else if (two->getType() == Float)
				return std::to_string(fmod(std::stod(one->toString()),
				                           std::stof(two->toString())));
			else
				return std::to_string(fmod(std::stod(one->toString()),
				                           std::stod(two->toString())));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(fmod(std::stod(two->toString()),
				                           std::stoi(one->toString())));
			else if (one->getType() == Float)
				return std::to_string(fmod(std::stod(two->toString()),
				                           std::stof(one->toString())));
			else
				return std::to_string(fmod(std::stod(two->toString()),
				                           std::stof(one->toString())));
		}
	}
}
