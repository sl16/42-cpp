/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:31 by vbartos           #+#    #+#             */
/*   Updated: 2024/04/25 13:47:27 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}


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

static bool isAllNumeric(std::string input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isdigit(*i))
			return (false);
	}
	return (true);
}

static bool isAllAlphabetic(std::string input)
{
	std::cout << "ERROR" << std::endl;
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isalpha(*i))
			return (false);
	}
	return (true);
}

static bool isAlphanumeric(std::string input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isalnum(*i))
			return (false);
	}
	return (true);
}

std::string parseInput(std::string field)
{
	std::string input;

	while (true)
	{
		std::cout << "Set contact's " << field << ": ";
		std::getline(std::cin, input);
		std::cout << std::endl;
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
	return (input);
}

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