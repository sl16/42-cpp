/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:47:39 by vbartos           #+#    #+#             */
/*   Updated: 2024/04/25 15:53:57 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

#include "../inc/Contact.hpp"
#include "../inc/PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
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
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << std::endl << "Unknown command. ";
	}
		
	return (0);
}