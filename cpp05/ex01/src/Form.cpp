/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:22:40 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/11 16:48:21 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTORS

Form::Form(): _name("Default"), _gradeExec(75), _gradeSign(75), _signed(false)
{	
	std::cout << "[form CONSTRUCTOR - " << getName() << "]" << std::endl;
}

Form::Form(std::string name, int gradeExec, int gradeSign): _name(name), _gradeExec(gradeExec), _gradeSign(gradeSign), _signed(false)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (Form::GradeTooHighException());
	else if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooLowException());
	
	std::cout << "[form CONSTRUCTOR - " << getName() << "]" << std::endl;
}

Form::~Form()
{
	std::cout << "[form DESTRUCTOR - " << getName() << "]" << std::endl;
}

Form::Form(const Form &other): _name(other._name), _gradeExec(other._gradeExec), _gradeSign(other._gradeSign), _signed(other._signed)
{
	std::cout << "[form COPY CONSTRUCTOR]" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	//nothing to do here because of const variables
	(void) other;
	return (*this);
}

// GETTERS

const std::string	Form::getName() const
{
	return (_name);
}

int					Form::getGradeSign() const
{
	return (_gradeSign);
}

int					Form::getGradeExec() const
{
	return (_gradeExec);
}

bool				Form::isSigned() const
{
	return (_signed);
}

// MEMEBER FUNCTIONS

void Form::beSigned(Bureaucrat &brc)
{
	if (brc.getGrade() <= getGradeSign())
		_signed = true;
	else
		throw (GradeTooLowException());
}

// EXCEPTIONS

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low.");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.");
}

// STREAM OVERLOADS

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "Form details: \n";
	os << "Name: " << obj.getName() << "\n";
	os << "Signed: ";
	if (obj.isSigned() == true)
		os << "yes";
	else
		os << "no";
	os << "\n" << "Grade to Sign: " << obj.getGradeSign() << "\n";
	os << "Grade to Execute: " << obj.getGradeExec() << "\n";
	return os;
}