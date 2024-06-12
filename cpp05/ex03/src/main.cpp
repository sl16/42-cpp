/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:53:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 15:21:23 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

int main(void)
{
	srand(time(0));
	// {
	// 	std::cout << std::endl << MAGENTA << "SUCCESSFUL SIGNING & EXECUTION - SHRUBBERY FORM" << RESET << std::endl << std::endl;

	// 	try
	// 	{
	// 		ShrubberyCreationForm form("AFIbushes1");
	// 		Bureaucrat brc("The bestest dood", 1);

	// 		std::cout << form << std::endl;
	// 		std::cout << brc << std::endl;
	// 		brc.signForm(form);
	// 		// std::cout << form << std::endl;
	// 		brc.executeForm(form);
			
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl; 
	// 	}
	// }

	// {
	// 	std::cout << std::endl << MAGENTA << "SUCCESSFUL SIGNING & UNSUCCESSFUL EXECUTION - SHRUBBERY FORM" << RESET << std::endl << std::endl;

	// 	try
	// 	{
	// 		ShrubberyCreationForm form("AFIbushes2");
	// 		Bureaucrat brc("An average dood", 140);

	// 		std::cout << form << std::endl;
	// 		std::cout << brc << std::endl;
	// 		brc.signForm(form);
	// 		// std::cout << form << std::endl;
	// 		brc.executeForm(form);
			
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl; 
	// 	}
	// }

	// {
	// 	std::cout << std::endl << MAGENTA << "UNSUCCESSFUL SIGNING & EXECUTION - SHRUBBERY FORM" << RESET << std::endl << std::endl;

	// 	try
	// 	{
	// 		ShrubberyCreationForm form("AFIbushes3");
	// 		Bureaucrat brc("The worst dood", 150);

	// 		std::cout << form << std::endl;
	// 		std::cout << brc << std::endl;
	// 		brc.signForm(form);
	// 		// std::cout << form << std::endl;
	// 		brc.executeForm(form);
			
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl; 
	// 	}
	// }

	// {
	// 	std::cout << std::endl << MAGENTA << "ROBOTOMY" << RESET << std::endl << std::endl;

	// 	try
	// 	{
	// 		RobotomyRequestForm form("Karel");
	// 		RobotomyRequestForm form2("Barel");
	// 		RobotomyRequestForm form3("Pharell");
	// 		RobotomyRequestForm form4("Aquarell");
	// 		Bureaucrat brc("Zaphod Beeblebrox", 1);
	// 		Bureaucrat brc2("Arthur", 100);

	// 		// std::cout << form << std::endl;
	// 		// std::cout << brc << std::endl;
	// 		brc.signForm(form);
	// 		brc.signForm(form2);
	// 		brc.signForm(form3);
	// 		brc2.signForm(form4);
	// 		// std::cout << form << std::endl;
	// 		brc.executeForm(form);
	// 		brc.executeForm(form2);
	// 		brc.executeForm(form3);
	// 		brc2.executeForm(form4);
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl; 
	// 	}
	// }

	// {
	// 	std::cout << std::endl << MAGENTA << "PRESIDENTIAL PARDON" << RESET << std::endl << std::endl;

	// 	try
	// 	{
	// 		PresidentialPardonForm form("A totally innocent Vogon");
	// 		PresidentialPardonForm form2("Just a dude having a bad day");
	// 		Bureaucrat brc("Zaphod Beeblebrox", 1);
	// 		Bureaucrat brc2("Arthur", 100);

	// 		// std::cout << form << std::endl;
	// 		// std::cout << brc << std::endl;
	// 		brc.signForm(form);
	// 		brc2.signForm(form2);
	// 		// std::cout << form << std::endl;
	// 		brc.executeForm(form);
	// 		brc2.executeForm(form2);
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl; 
	// 	}
	// }

	{
		std::cout << std::endl << MAGENTA << "SUCCESSFUL INTERN" << RESET << std::endl << std::endl;

		try
		{
			Bureaucrat brc("Zaphod Beeblebrox", 1);
			Intern intern;
			AForm *form;
			AForm *form2;
			AForm *form3;

			form = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
			form2 = intern.makeForm("shrubbery creation", "Zaphod Beeblebrox");
			form3 = intern.makeForm("robotomy request", "Zaphod Beeblebrox");

			// std::cout << form << std::endl;
			// std::cout << brc << std::endl;
			brc.signForm(*form);
			// brc2.signForm(form2);
			// std::cout << form << std::endl;
			brc.executeForm(*form);
			// brc2.executeForm(form2);

			delete form;
			delete form2;
			delete form3;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	{
		std::cout << std::endl << MAGENTA << "UNSUCCESSFUL INTERN" << RESET << std::endl << std::endl;

		Bureaucrat brc("Zaphod Beeblebrox", 1);
		Intern intern;
		AForm *form;

		form = intern.makeForm("coffee stained pardon", "Zaphod Beeblebrox");
		if (form != NULL)
		{
			brc.signForm(*form);
			brc.executeForm(*form);
		}
	}

	return (0);	
};