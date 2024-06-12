/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:47:29 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 15:19:19 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	
}

Intern::~Intern()
{
	
}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		// nothing to copy
	}
	
	return (*this);
}

AForm* Intern::makeShrubbery(std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makePardon(std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

AForm* Intern::makeRobotomy(std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

const char* Intern::FormNoMatchException::what() const throw()
{
	return ("Form does not match available forms.");
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	formCreator fptrArr[] = {&Intern::makeShrubbery, &Intern::makePardon, &Intern::makeRobotomy};
	// AForm* (*fptrArr[3])() = {&Intern::makeShrubbery, &Intern::makePardon, &Intern::makeRobotomy};
	std::string formArr[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formArr[i] == formName)
			{
				std::cout << "Intern creates " << formName << " form." << std::endl;
				return ((this->*fptrArr[i])(formTarget));
			}
		}
		throw(FormNoMatchException());
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl; 
	}
	return (NULL);
}