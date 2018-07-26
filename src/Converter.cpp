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
		return std::to_string(std::stoi(one->to_string()) +
                                                       std::stoi(two->to_string()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->to_string()) +
		                             std::stoi(two->to_string())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->to_string()) +
		                      std::stoi(two->to_string()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->to_string()) +
			                      std::stof(two->to_string()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->to_string()) +
			                      std::stoi(two->to_string()));
		else
			return std::to_string(std::stof(one->to_string()) +
			                      std::stof(two->to_string()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->to_string()) +
				                      std::stoi(two->to_string()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->to_string()) +
				                      std::stof(two->to_string()));
			else
				return std::to_string(std::stod(one->to_string()) +
				                      std::stod(two->to_string()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->to_string()) +
				                      std::stoi(one->to_string()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->to_string()) +
				                      std::stof(one->to_string()));
			else
				return std::to_string(std::stod(two->to_string()) +
				                      std::stod(one->to_string()));
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
		return std::to_string(std::stoi(one->to_string()) -
		                             std::stoi(two->to_string()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->to_string()) -
		                             std::stoi(two->to_string())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->to_string()) -
		                      std::stoi(two->to_string()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->to_string()) -
			                      std::stof(two->to_string()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->to_string()) -
			                      std::stoi(two->to_string()));
		else
			return std::to_string(std::stof(one->to_string()) -
			                      std::stof(two->to_string()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->to_string()) -
				                      std::stoi(two->to_string()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->to_string()) -
				                      std::stof(two->to_string()));
			else
				return std::to_string(std::stod(one->to_string()) -
				                      std::stod(two->to_string()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->to_string()) -
				                      std::stoi(one->to_string()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->to_string()) -
				                      std::stof(one->to_string()));
			else
				return std::to_string(std::stod(two->to_string()) -
				                      std::stod(one->to_string()));
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
		return std::to_string(std::stoi(one->to_string()) *
		                             std::stoi(two->to_string()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->to_string()) *
		                             std::stoi(two->to_string())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->to_string()) *
		                      std::stoi(two->to_string()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->to_string()) *
			                      std::stof(two->to_string()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->to_string()) *
			                      std::stoi(two->to_string()));
		else
			return std::to_string(std::stof(one->to_string()) *
			                      std::stof(two->to_string()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->to_string()) *
				                      std::stoi(two->to_string()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->to_string()) *
				                      std::stof(two->to_string()));
			else
				return std::to_string(std::stod(one->to_string()) *
				                      std::stod(two->to_string()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->to_string()) *
				                      std::stoi(one->to_string()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->to_string()) *
				                      std::stof(one->to_string()));
			else
				return std::to_string(std::stod(two->to_string()) *
				                      std::stod(one->to_string()));
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
		return std::to_string(std::stoi(one->to_string()) /
		                             std::stoi(two->to_string()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->to_string()) /
		                             std::stoi(two->to_string())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->to_string()) /
		                      std::stoi(two->to_string()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(std::stoi(one->to_string()) /
			                      std::stof(two->to_string()));
		else if (two->getType() != Float)
			return std::to_string(std::stof(one->to_string()) /
			                      std::stoi(two->to_string()));
		else
			return std::to_string(std::stof(one->to_string()) /
			                      std::stof(two->to_string()));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(std::stod(one->to_string()) /
				                      std::stoi(two->to_string()));
			else if (two->getType() == Float)
				return std::to_string(std::stod(one->to_string()) /
				                      std::stof(two->to_string()));
			else
				return std::to_string(std::stod(one->to_string()) /
				                      std::stod(two->to_string()));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(std::stod(two->to_string()) /
				                      std::stoi(one->to_string()));
			else if (one->getType() == Float)
				return std::to_string(std::stod(two->to_string()) /
				                      std::stof(one->to_string()));
			else
				return std::to_string(std::stod(two->to_string()) /
				                      std::stod(one->to_string()));
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
		return std::to_string(std::stoi(one->to_string()) %
		                             std::stoi(two->to_string()));
	else if (max == Int16)
		return std::to_string(CASTSH(std::stoi(one->to_string()) %
		                             std::stoi(two->to_string())));
	else if (max == Int32)
		return std::to_string(std::stoi(one->to_string()) %
		                      std::stoi(two->to_string()));
	else if (max == Float) {
		if (one->getType() != Float)
			return std::to_string(fmod(std::stoi(one->to_string()),
			                           std::stof(two->to_string())));
		else if (two->getType() != Float)
			return std::to_string(fmod(std::stof(one->to_string()),
			                           std::stoi(two->to_string())));
		else
			return std::to_string(fmod(std::stof(one->to_string()),
			                           std::stof(two->to_string())));
	}
	else {
		if (one->getType() == Double) {
			if (two->getType() != Float && two->getType() != Double)
				return std::to_string(fmod(std::stod(one->to_string()),
				                           std::stoi(two->to_string())));
			else if (two->getType() == Float)
				return std::to_string(fmod(std::stod(one->to_string()),
				                           std::stof(two->to_string())));
			else
				return std::to_string(fmod(std::stod(one->to_string()),
				                           std::stod(two->to_string())));
		}
		else {
			if (one->getType() != Float && one->getType() != Double)
				return std::to_string(fmod(std::stod(two->to_string()),
				                           std::stoi(one->to_string())));
			else if (one->getType() == Float)
				return std::to_string(fmod(std::stod(two->to_string()),
				                           std::stof(one->to_string())));
			else
				return std::to_string(fmod(std::stod(two->to_string()),
				                           std::stof(one->to_string())));
		}
	}
}
