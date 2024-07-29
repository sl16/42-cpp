/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:25:28 by vbartos           #+#    #+#             */
/*   Updated: 2024/07/29 14:49:25 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& other)
{
	_res = other._res;
}

const RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_res = other._res;
	}

	return (*this);
}

void RPN::validateInput(std::string& input)
{
	if (input.find_first_not_of("0123456789 */+-") != std::string::npos)
		throw std::invalid_argument("Error: wrong input (only provide single digits and '+-*/')");

	if (input.find_first_of("*/+-") == std::string::npos)
		throw std::invalid_argument("Error: wrong input (there must be atleast one operator)");
	
	if (input.c_str()[0] == ' ' || input.c_str()[input.size() - 1] == ' ')
		throw std::invalid_argument("Error: wrong input (no leading or trailing spaces)");

	int counter = 1;
	for (std::string::iterator it = input.begin(); it != input.end(); it++, counter++)
	{
		if (counter % 2 == 0)
		{
			if (*it != ' ')
				throw std::invalid_argument("Error: wrong input (each token must contain only one character, be separated with a space)");
		}
	}
}

void RPN::calculateRes(std::string& input)
{
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		// If space encountered, skip it
		if (*it == ' ')
			continue;
		
		// If digit encountered, convert it (by subtracting ASCII '0' value) and push it to stack
		if (std::isdigit(*it))
			_res.push(*it - '0');
		else
		{
			if (_res.size() < 2)
				throw std::runtime_error("Error: Not enough operands for operation");
			
			long long b = _res.top();
			_res.pop();
			long long a = _res.top();
			_res.pop();

			switch (*it)
			{
				case '+':
					_res.push(a + b);
					break;
				case '-':
					_res.push(a - b);
					break;
				case '*':
					_res.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Error: Division by zero is undefined");
					_res.push(a / b);
					break;
			}
		}
	}
	if (_res.size() != 1)
				throw std::runtime_error("Error: Invalid input");
	std::cout << "Result: " << _res.top() << std::endl;
}