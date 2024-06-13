/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:22:40 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/13 06:49:35 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTORS

AForm::AForm(): _name("Default"), _gradeExec(75), _gradeSign(75), _signed(false)
{	
	// std::cout << "[AForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

AForm::AForm(std::string name, int gradeExec, int gradeSign): _name(name), _gradeExec(gradeExec), _gradeSign(gradeSign), _signed(false)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (AForm::GradeTooHighException());
	else if (gradeSign > 150 || gradeExec > 150)
		throw (AForm::GradeTooLowException());
	
	// std::cout << "[AForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "[AForm DESTRUCTOR - " << getName() << "]" << std::endl;
}

AForm::AForm(const AForm &other): _name(other._name), _gradeExec(other._gradeExec), _gradeSign(other._gradeSign), _signed(other._signed)
{
	// std::cout << "[AForm COPY CONSTRUCTOR]" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	//nothing to do here because of const variables
	(void) other;
	return (*this);
}

// GETTERS

const std::string&	AForm::getName() const
{
	return (_name);
}

const int&			AForm::getGradeSign() const
{
	return (_gradeSign);
}

const int&			AForm::getGradeExec() const
{
	return (_gradeExec);
}

bool				AForm::isSigned() const
{
	return (_signed);
}

// MEMEBER FUNCTIONS

void AForm::beSigned(Bureaucrat &brc)
{
	if (brc.getGrade() <= getGradeSign())
		_signed = true;
	else
		throw (GradeTooLowException());
}

// EXCEPTIONS

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.");
}

const char* AForm::ExecutionNotSignedException::what() const throw()
{
	return ("The form is not signed.");
}

const char* AForm::ExecutionLowGradeException::what() const throw()
{
	return ("The executor does not qualify.");
}

// STREAM OVERLOADS

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << "AForm details: \n";
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