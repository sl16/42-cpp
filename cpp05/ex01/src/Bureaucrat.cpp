/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:56:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/11 16:20:34 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat(): _name("N/A")
{
	std::cout << "[brc CONSTRUCTOR - " << getName() << "]" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade = grade;
	
	std::cout << "[brc CONSTRUCTOR - " << getName() << "]" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[brc DESTRUCTOR - " << getName() << "]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	std::cout << "[brc COPY CONSTRUCTOR]" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// const name cannot be copied
		this->_grade = other.getGrade();
	}
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::raiseGrade()
{
	if ((_grade - 1) < 1)
		throw (Bureaucrat::GradeTooHighException());
	
	this->_grade--;
}

void Bureaucrat::lowerGrade()
{
	if ((_grade + 1) > 150)
		throw (Bureaucrat::GradeTooLowException());
	
	this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The proposed grade is too low (min: 150).");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The proposed grade is too high (max: 1).");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << "Bureaucrat details: \n";
    os << "Name: " << obj.getName() << "\n";
    os << "Grade: " << obj.getGrade() << "\n";
    return os;
}