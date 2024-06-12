/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:53:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 11:24:30 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

int main(void)
{
	srand(time(0));
	{
		std::cout << std::endl << MAGENTA << "SUCCESSFUL SIGNING & EXECUTION - SHRUBBERY FORM" << RESET << std::endl << std::endl;

		try
		{
			ShrubberyCreationForm form("AFIbushes1");
			Bureaucrat brc("The bestest dood", 1);

			std::cout << form << std::endl;
			std::cout << brc << std::endl;
			brc.signForm(form);
			// std::cout << form << std::endl;
			brc.executeForm(form);
			
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	{
		std::cout << std::endl << MAGENTA << "SUCCESSFUL SIGNING & UNSUCCESSFUL EXECUTION - SHRUBBERY FORM" << RESET << std::endl << std::endl;

		try
		{
			ShrubberyCreationForm form("AFIbushes2");
			Bureaucrat brc("An average dood", 140);

			std::cout << form << std::endl;
			std::cout << brc << std::endl;
			brc.signForm(form);
			// std::cout << form << std::endl;
			brc.executeForm(form);
			
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	{
		std::cout << std::endl << MAGENTA << "UNSUCCESSFUL SIGNING & EXECUTION - SHRUBBERY FORM" << RESET << std::endl << std::endl;

		try
		{
			ShrubberyCreationForm form("AFIbushes3");
			Bureaucrat brc("The worst dood", 150);

			std::cout << form << std::endl;
			std::cout << brc << std::endl;
			brc.signForm(form);
			// std::cout << form << std::endl;
			brc.executeForm(form);
			
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	{
		std::cout << std::endl << MAGENTA << "ROBOTOMY" << RESET << std::endl << std::endl;

		try
		{
			RobotomyRequestForm form("Karel");
			RobotomyRequestForm form2("Barel");
			RobotomyRequestForm form3("Pharell");
			RobotomyRequestForm form4("Aquarell");
			Bureaucrat brc("Zaphod Beeblebrox", 1);
			Bureaucrat brc2("Arthur", 100);

			// std::cout << form << std::endl;
			// std::cout << brc << std::endl;
			brc.signForm(form);
			brc.signForm(form2);
			brc.signForm(form3);
			brc2.signForm(form4);
			// std::cout << form << std::endl;
			brc.executeForm(form);
			brc.executeForm(form2);
			brc.executeForm(form3);
			brc2.executeForm(form4);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	{
		std::cout << std::endl << MAGENTA << "PRESIDENTIAL PARDON" << RESET << std::endl << std::endl;

		try
		{
			PresidentialPardonForm form("A totally innocent Vogon");
			PresidentialPardonForm form2("Just a dude having a bad day");
			Bureaucrat brc("Zaphod Beeblebrox", 1);
			Bureaucrat brc2("Arthur", 100);

			// std::cout << form << std::endl;
			// std::cout << brc << std::endl;
			brc.signForm(form);
			brc2.signForm(form2);
			// std::cout << form << std::endl;
			brc.executeForm(form);
			brc2.executeForm(form2);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	return (0);	
};