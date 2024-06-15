/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:59 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/15 15:57:15 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

#define SYMBOLS_INT	"-0123456789"
#define SYMBOLS_FLT	"-0123456789f."
#define SYMBOLS_DBL	"-0123456789."

// #define IS_CHAR		0
// #define IS_INT		1
// #define IS_FLOAT	2
// #define IS_DOUBLE	3

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
	
	public:
		static void convert(std::string value);	
};

enum ValueType
{
    IS_CHAR,
    IS_INT,
    IS_FLOAT,
    IS_DOUBLE
};

union ValueUnion
{
    char c;
    int i;
    float f;
    double d;
};

struct ScalarValue
{
    ValueType type;
    ValueUnion value;
};