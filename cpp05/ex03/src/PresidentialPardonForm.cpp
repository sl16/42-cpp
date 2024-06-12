/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:11:45 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 10:46:15 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Unspecified Pardon Form", 45, 72), _target("N/A")
{
	// std::cout << "[PresidentialPardonForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Pardon Form", 45, 72), _target(target)
{
	// std::cout << "[PresidentialPardonForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "[PresidentialPardonForm DESTRUCTOR - " << getName() << "]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other.getName(), other.getGradeExec(), other.getGradeSign())
{
	_target = other._target;
	// std::cout << "[PresidentialPardonForm COPY CONSTRUCTOR - " << getName() << "]" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	//nothing to do here because of const variables
	_target = other._target;
	return (*this);
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (isSigned() == false)
		throw (AForm::ExecutionNotSignedException());
	if (executor.getGrade() > getGradeExec())
		throw (AForm::ExecutionLowGradeException());

	std::cout << "Congrats! " << getTarget() << " has been pardoned by Zaphod Beeblobrox!" << std::endl;
}