/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/26 12:46:46 by vbartos          ###   ########.fr       */
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

static void skipHeader(std::ifstream& file, std::string& line)
{
	std::getline(file, line);
	if (line == "date,exchange_rate" || line == "date | value")
		std::getline(file, line);
}

static std::string trimSpaces(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return (str);
	size_t last = str.find_last_not_of(' ');
	
	return (str.substr(first, (last - first + 1)));
}

static bool formatIsValid(std::string& line)
{
	// There is one and only one delimiter " | "
	size_t posFirst = line.find_first_of('|');
	size_t posLast = line.find_last_of('|');
	if (posFirst != posLast || posFirst == std::string::npos)
	{
		std::cerr << "Error: wrong line format -> " << line << std::endl;
		return (false);
	}

	return (true);
}

/**
 * Checks if a given year is a leap year. If you didn't know (like me):
 * every 4 years is a leap year. Every 100 years is not a leap year.
 * Finally, every 400 years is a leap year.
 *
 * @param year The year to be checked.
 * @return True if the year is a leap year, false otherwise.
 */
static bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool dateIsValid(std::string& line, std::string& date)
{	
	// Extract date from line
	date = line.substr(0, line.find_first_of('|'));
	date = trimSpaces(date);
	
	// Check if date is in the format YYYY-MM-DD
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: wrong date format (expected format: \"YYYY-MM-DD\")" << std::endl;
		return (false);
	}

	// Extract year, month, day as integers
	std::istringstream iss(date);
	int year, month, day;
	char delimiter;
	iss >> year >> delimiter >> month >> delimiter >> day;

	// Validate year, month, day ranges
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: wrong date value (month) -> " << date << std::endl;
		return (false);
	}

	// Array to hold the number of days in each month
	int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > daysInMonth[month - 1])
	{
		std::cerr << "Error: wrong date value (day) -> " << date << std::endl;
		return (false);
	}

	// std::cout << "DATE VALIDATOR" << std::endl << std::endl;

	return (true);
}

static bool valueIsValid(std::string line, double& value)
{	
	// Extract value from line
	std::string valueStr = line.substr(line.find_first_of('|') + 2);
	
	// Check if value is a number
	char* end;
	value = std::strtod(valueStr.c_str(), &end);
	if (end != valueStr.c_str() + valueStr.size())
	{
		std::cerr << "Error: value is not a number" << std::endl;
		return (false);
	}

	// Check if value is a positive number in desired range
	if (value < 0 || value > 1000)
	{
		std::cerr << "Error: value must be between 0 and 1000" << std::endl;
		return (false);
	}

	// std::cout << "VALUE VALIDATOR" << std::endl << std::endl;
	
	return (true);
}

// MEMBER FUNCTIONS

int BitcoinExchange::parseDatabase(std::ifstream& file)
{
	std::string			line;
	std::string			date;
	std::string 		valueStr;
	double 				value;

	skipHeader(file, line);	
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		
		std::getline(ss, date, ',');
		std::getline(ss, valueStr);
		value = std::strtod(valueStr.c_str(), NULL);
		_database[date] = value;
	}

	return (0);
}

int BitcoinExchange::matchDate(std::string& date, double& value)
{
	std::map<std::string, double>::iterator it = _database.find(date);

	if (it != _database.end())
    	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else 
		std::cerr << "Error: exact date not found - searched date: " << date << std::endl;
	return (0);
}

void BitcoinExchange::lookUp(std::ifstream& file)
{	
	std::string line;

	skipHeader(file, line);
	while (std::getline(file, line))
	{
		// std::cout << "INPUT: " << line << std::endl;
		
		if (!formatIsValid(line))
			continue;

		std::string date;
		double		value;
		
		if (!dateIsValid(line, date) || !valueIsValid(line, value))
			continue;

		matchDate(date, value);
	}
	
	// for (std::map<std::string, double>::const_iterator it = _input.begin(); it != _input.end(); ++it)
	// {
		
		
	// }
}
