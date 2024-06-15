/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/15 15:55:39 by vbartos          ###   ########.fr       */
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

static char		toChar(std::string value)
{
	return (static_cast<char>(value[0]));
}

static int		toInt(std::string value)
{
	return (atoi(value.c_str()));
}

static float	toFloat(std::string value)
{
	return (atof(value.c_str()));
}

static double	toDouble(std::string value)
{
	return (atof(value.c_str()));
}

static ScalarValue convertToOriginal(std::string value)
{
	ScalarValue res;
	
	if (isChar(value))
	{
		res.type = IS_CHAR;
		res.value.c = toChar(value);
	}
	else if (isInt(value))
	{
		res.type = IS_INT;
		res.value.i = toInt(value);
	}
	else if (isFloat(value))
	{
		res.type = IS_FLOAT;
		res.value.f = toFloat(value);
	}
	else if (isDouble(value))
	{
		res.type = IS_DOUBLE;
		res.value.d = toDouble(value);
	}
	else
	{
		std::cout << "I don't know how to convert that. Are you crazy?!" << std::endl;
		exit(1);
	}
	return (res);
}

static void printChar(ScalarValue valueOg)
{
	std::cout << "char: \t";
	if (valueOg.value.c < 32 || valueOg.value.c > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << valueOg.value.c << std::endl;
	std::cout << "int: \t" << static_cast<int>(valueOg.value.c) << std::endl;
	std::cout << "float: \t" << std::fixed << std::setprecision(1) << static_cast<float>(valueOg.value.c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(valueOg.value.c) << std::endl;
}

static void printInt(ScalarValue valueOg)
{
	std::cout << "char: \t";
	if (valueOg.value.i < 32 || valueOg.value.i > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(valueOg.value.i) << std::endl;
	std::cout << "int: \t" << valueOg.value.i << std::endl;
	std::cout << "float: \t" << std::fixed << std::setprecision(1) << static_cast<float>(valueOg.value.i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(valueOg.value.i) << std::endl;
}

static void printFloat(ScalarValue valueOg)
{
	std::cout << "char: \t";
	if (valueOg.value.f < 32 || valueOg.value.f > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(valueOg.value.f) << std::endl;
	std::cout << "int: \t" << static_cast<int>(valueOg.value.f) << std::endl;
	std::cout << "float: \t" << std::fixed << std::setprecision(1) << valueOg.value.f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(valueOg.value.f) << std::endl;
}

static void printDouble(ScalarValue valueOg)
{
	std::cout << "char: \t";
	if (valueOg.value.d < 32 || valueOg.value.d > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(valueOg.value.d) << std::endl;
	std::cout << "int: \t" << static_cast<int>(valueOg.value.d) << std::endl;
	std::cout << "float: \t" << std::fixed << std::setprecision(1) << static_cast<float>(valueOg.value.d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << valueOg.value.d << std::endl;
}

// MEMBER FUNCTIONS

void ScalarConverter::convert(std::string value)
{
	ScalarValue valueOg;
	
	valueOg = convertToOriginal(value);

	switch (valueOg.type)
	{
		case IS_CHAR:
			printChar(valueOg);
			break;
		case IS_INT:
			printInt(valueOg);
			break;
		case IS_FLOAT:
			printFloat(valueOg);
			break;
		case IS_DOUBLE:
			printDouble(valueOg);
			break;
	}

}