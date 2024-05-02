/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:47 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/02 14:29:21 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

// CONSTRUCTOR && DESTRUCTOR

PhoneBook::PhoneBook(void)
{
	_contactsTotal = 0;
	
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

// SETTERS && GETTERS

int	PhoneBook::getContactsTotal(void) const
{
	return (this->_contactsTotal);
}

// CUSTOM MEMBER FUNCTIONS && HELPER FUNCTIONS

void PhoneBook::add(void)
{
	if (_contactsTotal == NUM_OF_CONTACTS)
	{
		std::cout << "WARNING: The phonebook has reached the maximum number of saved contacts. The oldest entry will be overwritten." << std::endl;
		for (int i = 1; i < _contactsTotal; i++)
			_contacts[i - 1] = _contacts[i];
		_contacts[NUM_OF_CONTACTS - 1].setContact();
	}
	else
	{
		_contacts[_contactsTotal].setContact();
		_contactsTotal++;
		std::cout << "Contact succesfully added. Returning to main menu." << std::endl;
	}
}

std::string formatColumn(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

/**
 * @brief Displays the available contacts in the phone book and allows the user
 * to view detailed informationabout a specific contact.
 * 
 * This function prints the available contacts in a column format, including
 * the index, name, surname, and nickname of each contact. It then prompts
 * the user to enter the corresponding index of a contact to view its detailed
 * information, such as first name, last name, nickname, phone number, and darkest secret.
 * The function performs input validation to ensure that the index entered is valid.
 * 
 * @return void
 */
void PhoneBook::search(void)
{
	int 		indexInt;
	std::string indexStr;
	
	// IF NO AVAILABLE ENTRIES, RETURNS
	std::cout << "----------------" << std::endl;
	std::cout << "Displaying available contacts..." << std::endl;
	if (_contactsTotal == 0)
	{
		std::cout << "The phonebook currently holds no contacts." << std::endl;
		return ;
	}

	// PRINTS COLUMN HEADER
	std::cout << "----------------" << std::endl;
	std::cout << GREEN;
	std::cout << std::setw(10) << std::left << std::setfill('_') << "INDEX" << "_";
	std::cout << std::setw(10) << std::left << std::setfill('_') << "NAME" << "_";
	std::cout << std::setw(10) << std::left << std::setfill('_') << "SURNAME" << "_";
	std::cout << std::setw(10) << std::left << std::setfill('_') << "NICKNAME" << std::endl;
	std::cout << RESET;

	// PRINTS ENTRIES IN COLUMN FORMAT
	for (int i = 0; i < _contactsTotal; ++i)
	{
		std::cout << std::setw(10) << std::right << std::setfill(' ') << i + 1 << "|";
		std::cout << std::setw(10) << std::right << std::setfill(' ') << formatColumn(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << std::setfill(' ') << formatColumn(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << std::setfill(' ') << formatColumn(_contacts[i].getNickName()) << std::endl;
	}
	
	// PRINTS ENTRIES IN DETAILED FORMAT IF INDEX PROVIDED
	std::cout << "----------------" << std::endl;
	std::cout << "For detailed contact display, enter the corresponding index: ";
	std::getline(std::cin, indexStr);
	std::cout << std::endl;
	if (!isAllNumeric(indexStr))
	{
		std::cout << "Index must be a digit. Returning to main menu." << std::endl;
		return ;
	}
	indexInt = std::atoi(indexStr.c_str());
	if (indexInt < 1 || indexInt > _contactsTotal)
	{
		std::cout << "No such index available. Returning to main menu." << std::endl;
		return ;
	}
	indexInt--;
	std::cout << "First name: " << _contacts[indexInt].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[indexInt].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[indexInt].getNickName() << std::endl;
	std::cout << "Phone number: " << _contacts[indexInt].getPhoneNum() << std::endl;
	std::cout << "Darkest secret: " << _contacts[indexInt].getDarkestSecret() << std::endl;
	std::cout << "----------------" << std::endl;
}