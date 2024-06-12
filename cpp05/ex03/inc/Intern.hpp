/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:47:10 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 15:00:17 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		
		AForm* makeForm(std::string formName, std::string formTarget);

		AForm* makeShrubbery(std::string formTarget);
		AForm* makePardon(std::string formTarget);
		AForm* makeRobotomy(std::string formTarget);

		class FormNoMatchException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

typedef AForm* (Intern::*formCreator)(std::string);
