/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:31 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/02 14:29:18 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

// CONSTRUCTOR && DESTRUCTOR

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

// SETTERS && GETTERS

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getPhoneNum(void) const
{
	return (this->_phoneNum);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void Contact::setFirstName(std::string input)
{
	this->_firstName = input;
}

void Contact::setLastName(std::string input)
{
	this->_lastName = input;
}

void Contact::setNickName(std::string input)
{
	this->_nickName = input;
}

void Contact::setPhoneNum(std::string input)
{
	this->_phoneNum = input;
}

void Contact::setDarkestSecret(std::string input)
{
	this->_darkestSecret = input;
}

// CUSTOM MEMBER FUNCTIONS && HELPER FUNCTIONS

/**
 * @brief Parses the input for a specific field.
 * 
 * This function prompts the user to set the contact's field and validates the input based on the field type.
 * First name and last name must be alphabetic only, phone number numeric only, and nickname and darkest secret
 * can combine both.
 * 
 * @param field The field to set (e.g., "phone number", "first name", etc.).
 * @return The user input for the specified field.
 */
std::string parseInput(std::string field)
{
	std::string input;

	while (true)
	{
		std::cout << "Set contact's " << field << ": ";
		std::getline(std::cin, input);
		if (input != "" && !isAllSpaces(input))
		{
			if (field == "phone number")
			{
				if (isAllNumeric(input))
					break;
				else
					std::cout << "Please input only numeric characters." << std::endl;
			}
			else if (field == "first name" || field == "last name")
			{
				if (isAllAlphabetic(input))
					break;
				else
					std::cout << "Please input only alphabetic characters." << std::endl;
			}
			else if (field == "nickname" || field == "darkest secret")
			{
				if (isAlphanumeric(input))
					break;
				else
					std::cout << "Please input only alphanumeric characters." << std::endl;
			}
		}
		else
			std::cout << "The provided input cannot be empty." << std::endl;
	}
	return (input);
}

/**
 * @brief Sets the contact information.
 * 
 * This function prompts the user to enter the contact information, such as first name, last name, nickname,
 * phone number, and darkest secret. It uses the parseInput function to validate and store the user input.
 * 
 * @return void
 */
void Contact::setContact(void)
{
	std::cout << "----------------" << std::endl;
	setFirstName(parseInput("first name"));
	setLastName(parseInput("last name"));
	setNickName(parseInput("nickname"));
	setPhoneNum(parseInput("phone number"));
	setDarkestSecret(parseInput("darkest secret"));
	std::cout << "----------------" << std::endl;
}