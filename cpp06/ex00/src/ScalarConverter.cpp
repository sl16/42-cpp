/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/17 12:57:46 by vbartos          ###   ########.fr       */
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

static char		stringToChar(std::string value)
{
	return (static_cast<char>(value[0]));
}

static int 		stringToInt(std::string value, ScalarValue data)
{
    std::istringstream iss(value);
    long long intVal;

    if (!(iss >> intVal) || intVal < std::numeric_limits<int>::min() || intVal > std::numeric_limits<int>::max())
		data.valid = false;
    return (atoi(value.c_str()));
}

static float	stringToFloat(std::string value)
{
	return (atof(value.c_str()));
}

static double	stringToDouble(std::string value)
{
	return (atof(value.c_str()));
}

static ScalarValue convertToOriginal(std::string value)
{
	ScalarValue res;
	
	if (isChar(value))
	{
		res.type = IS_CHAR;
		res.c = stringToChar(value);
		std::cout << "ogType: char" << std::endl << std::endl;
	}
	else if (isInt(value))
	{
		res.type = IS_INT;
		res.i = stringToInt(value, res);
		std::cout << "ogType: int" << std::endl << std::endl;
	}
	else if (isFloat(value))
	{
		res.type = IS_FLOAT;
		res.f = stringToFloat(value);
		std::cout << "ogType: float" << std::endl << std::endl;
	}
	else if (isDouble(value))
	{
		res.type = IS_DOUBLE;
		res.d = stringToDouble(value);
		std::cout << "ogType: double" << std::endl << std::endl;
	}
	else
	{
		std::cout << "I don't know how to convert that. Are you crazy?!" << std::endl;
		exit(1);
	}
	return (res);
}

static void	typeToChar(ScalarValue ogValue, ScalarValue &res)
{
	if (ogValue.type == IS_CHAR)
	{
		res.c = ogValue.c;
		return ;
	}
	

}

static void	typeToInt(ScalarValue ogValue, ScalarValue &res)
{
	if (ogValue.type == IS_INT)
	{
		res.i = ogValue.i;
		return ;
	}
}

static void	typeToFloat(ScalarValue ogValue, ScalarValue &res)
{
	if (ogValue.type == IS_FLOAT)
	{
		res.f = ogValue.f;
		return ;
	}
}

static void	typeToDouble(ScalarValue ogValue, ScalarValue &res)
{
	if (ogValue.type == IS_DOUBLE)
	{
		res.d = ogValue.d;
		return ;
	}
}

static ScalarValue convertFromOriginal(ScalarValue &ogValue, ValueType convertToType)
{
	ScalarValue res;
	
	if (convertToType == IS_CHAR)
	{
		res.type = IS_CHAR;
		typeToChar(ogValue, res);
	}
	else if (convertToType == IS_INT)
	{
		res.type = IS_INT;
		typeToInt(ogValue, res);
	}
	else if (convertToType == IS_FLOAT)
	{
		res.type = IS_FLOAT;
		typeToFloat(ogValue, res);
	}
	else if (convertToType == IS_DOUBLE)
	{
		res.type = IS_DOUBLE;
		typeToDouble(ogValue, res);
	}
	return (res);
}

static void printValues(ScalarValue valueC, ScalarValue valueI, ScalarValue valueF, ScalarValue valueD)
{
	std::cout << "char: \t";
	if (valueC.valid == false)
		std::cout << "impossible" << std::endl;
	else if (valueC.displayable == false)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << valueC.c << std::endl;

	std::cout << "int: \t";
	if (valueI.valid == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << valueI.i << std::endl;

	std::cout << "float: \t";
	if (valueF.valid == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << valueF.f << std::endl;

	std::cout << "double: \t";
	if (valueD.valid == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << valueD.d << std::endl;
}

// MEMBER FUNCTIONS

void ScalarConverter::convert(std::string value)
{
	ScalarValue valueOg;
	ScalarValue valueC;
	ScalarValue valueI;
	ScalarValue valueF;
	ScalarValue valueD;
	
	valueOg = convertToOriginal(value);
	valueC = convertFromOriginal(valueOg, IS_CHAR);
	valueI = convertFromOriginal(valueOg, IS_INT);
	valueF = convertFromOriginal(valueOg, IS_FLOAT);
	valueD = convertFromOriginal(valueOg, IS_DOUBLE);

	printValues(valueC, valueI, valueF, valueD);
	

	// switch (valueOg.type)
	// {
	// 	case IS_CHAR:
	// 		printChar(valueOg);
	// 		break;
	// 	case IS_INT:
	// 		printInt(valueOg);
	// 		break;
	// 	case IS_FLOAT:
	// 		printFloat(valueOg);
	// 		break;
	// 	case IS_DOUBLE:
	// 		printDouble(valueOg);
	// 		break;
	// }

}