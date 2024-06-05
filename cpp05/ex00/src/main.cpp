/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:53:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/05 17:04:17 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

int main(void)
{
	std::cout << std::endl << MAGENTA << "GRADE IN LIMITS" << RESET << std::endl << std::endl;
	
	try
	{
		Bureaucrat bob("Bob", 50);
		std::cout << bob;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl; 
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl; 
	}

	std::cout << std::endl << MAGENTA << "GRADE TOO LOW" << RESET << std::endl << std::endl;
	
	try
	{
		Bureaucrat rob("Rob", 151);
		std::cout << rob;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl; 
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl; 
	}

	std::cout << std::endl << MAGENTA << "GRADE TOO HIGH" << RESET << std::endl << std::endl;
	
	try
	{
		Bureaucrat zob("Zob", 0);
		std::cout << zob;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl; 
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl; 
	}

	std::cout << std::endl << MAGENTA << "GRADE RAISED OVER LIMIT" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat gob("Gob", 1);
		std::cout << gob;
		std::cout << "Calling .raiseGrade" << std::endl;
		gob.raiseGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl; 
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl; 
	}

	std::cout << std::endl << MAGENTA << "GRADE LOWERED UNDER LIMIT" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat cob("Cob", 150);
		std::cout << cob;
		std::cout << "Calling .lowerGrade" << std::endl;
		cob.lowerGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl; 
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl; 
	}

	return (0);	
}