/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:38:33 by vbartos           #+#    #+#             */
/*   Updated: 2024/04/25 15:58:35 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

#define NUM_OF_CONTACTS	2

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "./Contact.hpp"
#include "./utils.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		int	getContactsTotal(void) const;

		void add(void);
		void search(void);
		
	private:
		Contact _contacts[NUM_OF_CONTACTS];
		int		_contactsTotal;
};

#endif