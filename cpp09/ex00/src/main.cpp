/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:12:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/26 15:13:27 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Please provide an input file (usage: ./btc <input>)" << std::endl;
		exit(1);
	}
	std::ifstream input(argv[1]);
	if (input.fail())
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		exit(1);
	}
	std::ifstream database("data.csv");
	if (database.fail())
	{
		std::cerr << "Error: Could not open file data.csv" << std::endl;
		exit(1);
	}
	
	BitcoinExchange exchange;
	exchange.parseDatabase(database);
	exchange.lookUp(input);

	return (0);
}