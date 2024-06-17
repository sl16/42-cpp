/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:59 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/17 16:21:24 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <sstream>

#define SYMBOLS_INT	"-0123456789"
#define SYMBOLS_FLT	"-0123456789f."
#define SYMBOLS_DBL	"-0123456789."

#define IMPOSSIBLE	"impossible"
#define NON_DISPL	"non-displayable"

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
    IS_DOUBLE,
	IS_NAN,
	IS_INF_POS,
	IS_INF_NEG
};

// union ValueUnion
// {
//     char c;
//     int i;
//     float f;
//     double d;
// };

// struct ScalarValue
// {
//     ValueType 		type;
//     unsigned char	c;
// 	int				i;
// 	float			f;
// 	double			d;
// 	bool		valid = true;
// 	bool		displayable = true;
// };