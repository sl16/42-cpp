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

#include <iostream>
#include <string>
#include "./Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		int	getContactsTotal(void) const;

		void add(void);
		void search(void);
		
	private:
		Contact _contacts[8];
		int		_contactsTotal;
};

#endif