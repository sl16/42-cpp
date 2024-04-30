/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:47 by vbartos           #+#    #+#             */
/*   Updated: 2024/04/25 16:02:21 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::getContactsTotal(void) const
{
	return (this->_contactsTotal);
}

void PhoneBook::add(void)
{
	if (_contactsTotal == 8)
	{
		
	}
		// implement contact reassignment
	_contacts[_contactsTotal].setContact();
}

void PhoneBook::search(void)
{
	std::cout << "Totally displaying contacts:" << std::endl;
}