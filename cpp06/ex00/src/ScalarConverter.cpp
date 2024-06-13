/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/13 13:30:42 by vbartos          ###   ########.fr       */
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

// MEMBER FUNCTIONS

void ScalarConverter::convert(std::string value)
{
	ScalarValue valueOg;
	
	valueOg = convertToOriginal(value);

	std::cout << valueOg.value.c << std::endl;
	std::cout << valueOg.value.i << std::endl;
	std::cout << valueOg.value.f << std::endl;
	std::cout << valueOg.value.d << std::endl;

	std::cout << "char: \t" << static_cast<char>(valueOg.value.c) << std::endl;
	std::cout << "int: \t" << static_cast<int>(valueOg.value.i) << std::endl;
	std::cout << "float: \t" << static_cast<float>(valueOg.value.f) << std::endl;
	std::cout << "double: \t" << static_cast<double>(valueOg.value.d)<< std::endl;

}