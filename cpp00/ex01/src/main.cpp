/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:47:39 by vbartos           #+#    #+#             */
/*   Updated: 2024/04/23 16:38:18 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

#include <iostream>

int main(void)
{
	std::string	cmd;
	
	std::cout << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << GREEN << "[ADD]" << RESET << "\t\t save a new contact" << std::endl;
	std::cout << GREEN << "[SEARCH]" << RESET << "\t display a specific contact" << std::endl;
	std::cout << GREEN << "[EXIT]" << RESET << "\t\t exit the program" << std::endl;
	std::cout << "----------------" << std::endl;
	
	while (true)
	{
		std::cout << "Enter command:" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD");
		// add functionality
		else if (cmd == "SEARCH");
		// add functionality
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Unknown command. ";
	}
		
	return (0);
}