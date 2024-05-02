/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:49:08 by vbartos           #+#    #+#             */
/*   Updated: 2024/04/25 15:27:49 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

#include "./utils.hpp"

class Contact
{
	public:
		Contact();
		~Contact();
		
		void setContact(void);
		void setFirstName(std::string input);
		void setLastName(std::string input);
		void setNickName(std::string input);
		void setPhoneNum(std::string input);
		void setDarkestSecret(std::string input);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNum(void) const;
		std::string getDarkestSecret(void) const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNum;
		std::string	_darkestSecret;
};

#endif