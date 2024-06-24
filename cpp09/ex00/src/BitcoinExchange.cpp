/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/24 08:58:57 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// CONSTRUCTION AND DESTRUCTION

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

// STATIC FUNCTIONS

static void	printDatabase(const std::map<std::string, double>& database)
{
	for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); ++it)
		std::cout << it->first << " | " << it->second << std::endl;
}

static std::string trimSpaces(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return (str);
	size_t last = str.find_last_not_of(' ');
	
	return (str.substr(first, (last - first + 1)));
}

// static bool lineIsValid(std::string line)
// {
// 	// Find the position of " | "
// 	size_t pos = line.find(" | ");
// 	if (pos == std::string::npos)
// 		return (false);

// 	// Split the line into date and value
// 	std::string date = line.substr(0, pos);
// 	std::string valueStr = line.substr(pos + 3);

// 	// Check if date is in the format YYYY-MM-DD
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 		return (false);

// 	// Check if value is a number
// 	char* end;
// 	std::strtod(valueStr.c_str(), &end);
// 	if (end != valueStr.c_str() + valueStr.size())
// 		return (false);

// 	// Line is valid
// 	return (true);
// }

// MEMBER FUNCTIONS

void BitcoinExchange::processLine(const std::string& line, char delim)
{
	std::stringstream ss(line);
	std::string date;
	std::string valueStr;
	double value;

	// Parse date and value separately from stringstream
	std::getline(ss, date, delim);
	std::getline(ss, valueStr);
	value = std::strtod(valueStr.c_str(), NULL);
	// std::cout << "date: " << date << ", value: " << value << std::endl;

	// Store parsed data in relevant database
	if (delim == ',')
		_database[date] = value;
	else
		_input[trimSpaces(date)] = value;
}

int BitcoinExchange::parseDatabase(std::ifstream& file, char delim)
{
	std::string line;

	// If there is a data header on the first line, skip it
	std::getline(file, line);
	if (line != "date,exchange_rate" && line != "date | value")
		processLine(line, delim);

	// Parse each line
	while (std::getline(file, line))
		processLine(line, delim);

	printDatabase(_input);

	return (0);
}

void BitcoinExchange::lookUp()
{
	for (std::map<std::string, double>::const_iterator it = _input.begin(); it != _input.end(); ++it)
	{
		
		
	}
}