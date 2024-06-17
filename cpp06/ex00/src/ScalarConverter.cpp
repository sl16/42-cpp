/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/17 14:27:24 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

// CONSTRUCTORS AND DESTRUCTORS

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return (*this);
}

// STATIC NON-MEMBER FUNCTIONS

static bool isChar(std::string value)
{
	if (value.size() == 1 && !isdigit(value[0]))
		return (true);
	else
		return (false);
}

static bool isInt(std::string value)
{
	if (value.find_first_not_of(SYMBOLS_INT) == std::string::npos)
		return (true);
	else
		return (false);
}

static bool isFloat(std::string value)
{
	if (value.find_first_not_of(SYMBOLS_FLT) == std::string::npos
		&& value.find_first_of('.') == value.find_last_of('.')
		&& value.find_first_of('f') == value.find_last_of('f'))
		return (true);
	else
		return (false);
}

static bool isDouble(std::string value)
{
	if (value.find_first_not_of(SYMBOLS_DBL) == std::string::npos
		&& value.find_first_of('.') == value.find_last_of('.'))
		return (true);
	else
		return (false);
}

static bool isNan(std::string value)
{
	if (value == "nanf" || value == "nan")
		return (true);
	else
		return (false);
}

static bool isInfPos(std::string value)
{
	if (value == "+inff" || value == "+inf")
		return (true);
	else
		return (false);
}

static bool isInfNeg(std::string value)
{
	if (value == "-inff" || value == "-inf")
		return (true);
	else
		return (false);
}

static char		stringToChar(std::string value)
{
	return (static_cast<char>(value[0]));
}

static long 	stringToInt(std::string value)
{
    return (atol(value.c_str()));
}

static float	stringToFloat(std::string value)
{
	return (std::strtof(value.c_str(), NULL));
}

static double	stringToDouble(std::string value)
{
	return (std::strtod(value.c_str(), NULL));
}

ValueType getType(std::string value)
{	
	if (isChar(value))
		return (IS_CHAR);
	else if (isInt(value))
		return (IS_INT);
	else if (isFloat(value))
		return (IS_FLOAT);
	else if (isDouble(value))
		return (IS_DOUBLE);
	else if (isNan(value))
		return (IS_NAN);
	else if (isInfNeg(value))
		return (IS_INF_NEG);
	else if (isInfPos(value))
		return (IS_INF_POS);
	else
	{
		std::cout << "I don't know how to convert that. Are you crazy?!" << std::endl;
		exit(1);
	}
}

void printFromChar(unsigned char c)
{
	std::cout << "char: \t";
	if (c < 32 || c > 126)
		std::cout << NON_DISPL << std::endl;
	else
		std::cout << c << std::endl;
	
	std::cout << "int: \t" << static_cast<int>(c) << std::endl;

	std::cout << "float: \t" << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void printFromInt(long i)
{
	std::cout << "char: \t";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << IMPOSSIBLE << std::endl;
	else if (i < 32 || i > 126)
		std::cout << NON_DISPL << std::endl;
	else
		std::cout << static_cast<char>(i) << std::endl;

	std::cout << "int: \t" << std::endl;
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << IMPOSSIBLE << std::endl;
	else
		std::cout << i;
		
	std::cout << "float: \t" << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void printFromFloat(float f)
{
	std::cout << "char: \t";
	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << IMPOSSIBLE << std::endl;
	else if (f < 32 || f > 126)
		std::cout << NON_DISPL << std::endl;
	else
		std::cout << static_cast<char>(f) << std::endl;
	
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << IMPOSSIBLE << std::endl;
	else
		std::cout << f;

	std::cout << "float: \t" << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void printFromDouble(double d)
{
	std::cout << "char: \t";
	if (d < 32 || d > 126)
		std::cout << NON_DISPL << std::endl;
	else
		std::cout << static_cast<char>(d) << std::endl;
	
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << IMPOSSIBLE << std::endl;
	else
		std::cout << d;

	std::cout << "float: \t" << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void printPseudo(std::string str_value, ValueType ogType)
{
	float			f;
	double			d;
	
	if (ogType == IS_INF_POS)
	{
		f = static_cast<float>(std::numeric_limits<float>::infinity());
		d = static_cast<double>(std::numeric_limits<double>::infinity());
	}
	else if (ogType == IS_INF_NEG)
	{
		f = static_cast<float>(std::numeric_limits<float>::infinity() * -1.f);
		d = static_cast<double>(std::numeric_limits<double>::infinity() * -1.);
	}
	else if (ogType == IS_NAN)
	{
		f = static_cast<float>(std::numeric_limits<float>::quiet_NaN());
		d = static_cast<double>(std::numeric_limits<double>::quiet_NaN());
	}
	std::cout << "char:\t" << IMPOSSIBLE << std::endl;
	std::cout << "int:\t" << IMPOSSIBLE << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

// MEMBER FUNCTIONS

void ScalarConverter::convert(std::string str_value)
{
	unsigned char	c;
	long			i;
	float			f;
	double			d;
		
	ValueType ogType = getType(str_value);

	switch(ogType)
	{
	    case IS_CHAR:
			c = stringToChar(str_value);
			printFromChar(c);
	        break;
	    case IS_INT:
	        i = stringToInt(str_value);
			printFromInt(i);
	        break;
	    case IS_FLOAT:
	        f = stringToFloat(str_value);
			printFromFloat(f);
	        break;
	    case IS_DOUBLE:
	        d = stringToDouble(str_value);
			printFromDouble(d);
	        break;
		case IS_NAN:
		case IS_INF_NEG:
		case IS_INF_POS:
			printPseudo(str_value, ogType);
			break;
	    default:
			std::cout << "I don't know how to convert that. Are you crazy?!" << std::endl;
	}

}