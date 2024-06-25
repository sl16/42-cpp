/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/25 14:54:31 by vbartos          ###   ########.fr       */
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
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return (*this);
}

// STATIC FUNCTIONS

// static void	printDatabase(const std::map<std::string, double>& database)
// {
// 	for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); ++it)
// 		std::cout << it->first << " | " << it->second << std::endl;
// }

static std::string trimSpaces(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return (str);
	size_t last = str.find_last_not_of(' ');
	
	return (str.substr(first, (last - first + 1)));
}

static bool dateIsValid(std::string date)
{
	// Check if date is in the format YYYY-MM-DD
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	
}

static bool lineIsValid(std::string line)
{
	// There is one and only one delimiter " | "
	size_t posFirst = line.find_first_of('|');
	size_t posLast = line.find_last_of('|');
	if (posFirst != posLast || posFirst == std::string::npos)
		return (false);

	// Split the line into date and value. Trim spaces around date (spaces for value are handled by strtod)
	std::string date = line.substr(0, posFirst);
	date = trimSpaces(date);
	std::string valueStr = line.substr(posFirst + 2);

	// Check date
	if (!dateIsValid(date))
		return (false);
	

	// Check if value is a number
	char* end;
	std::strtod(valueStr.c_str(), &end);
	if (end != valueStr.c_str() + valueStr.size())
		return (false);

	// Line is valid
	return (true);
}

// MEMBER FUNCTIONS

void BitcoinExchange::processLine(const std::string& line)
{
	std::stringstream ss(line);
	std::string date;
	std::string valueStr;
	double value;

	// Separate date and value, save it in map
	std::getline(ss, date, ',');
	std::getline(ss, valueStr);
	value = std::strtod(valueStr.c_str(), NULL);
	_database[date] = value;
}

int BitcoinExchange::parseDatabase(std::ifstream& file)
{
	std::string line;

	// If there is a data header on the first line, skip it
	std::getline(file, line);
	if (line != "date,exchange_rate" && line != "date | value")
		processLine(line);

	// Parse each line
	while (std::getline(file, line))
		processLine(line);

	return (0);
}

void BitcoinExchange::lookUp(std::ifstream& file)
{
	
	std::string line;

	// If there is a data header on the first line, skip it
	std::getline(file, line);
	if (line == "date,exchange_rate" || line == "date | value")
		std::getline(file, line);

	// Parse and match lines
	while (std::getline(file, line))
	{
		if (!lineIsValid(line))
			exit (1);
	}
	
	// for (std::map<std::string, double>::const_iterator it = _input.begin(); it != _input.end(); ++it)
	// {
		
		
	// }
}