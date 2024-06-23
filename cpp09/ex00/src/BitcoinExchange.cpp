/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/23 16:34:48 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_database = other._database;
	_input = other._input;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
		_input = other._input;
	}
	return (*this);
}

static bool lineIsValid(std::string)
{
	
	
}

int		BitcoinExchange::parseDatabase(std::ifstream& file, char delim)
{
	std::string line;

	while (std::getline(file, line))
	{
		lineIsValid(line);
		
		std::stringstream	ss(line);
		std::string			date;
		std::string			valueStr;
		double				value;

		std::getline(ss, date, delim);
		std::getline(ss, valueStr);
		value = std::strtod(valueStr.c_str(), NULL);
		std::cout << "date: " << date << ", value: " << value << std::endl;
		if (delim == ',')
			_database[date] = value;
		else
			_input[date] = value;
	}

	// std::cout << std::endl << std::endl;
	// if (delim != ',') {
	// 	for (std::map<std::string, double>::const_iterator it = _input.begin(); it != _input.end(); ++it)
	// 		std::cout << it->first << " | " << it->second << std::endl;
	// }

	return (0);
}
