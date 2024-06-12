/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:11:45 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 10:46:15 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Unspecified Robotomy Form", 45, 72), _target("N/A")
{
	// std::cout << "[RobotomyRequestForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Form", 45, 72), _target(target)
{
	// std::cout << "[RobotomyRequestForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "[RobotomyRequestForm DESTRUCTOR - " << getName() << "]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other.getName(), other.getGradeExec(), other.getGradeSign())
{
	_target = other._target;
	// std::cout << "[RobotomyRequestForm COPY CONSTRUCTOR - " << getName() << "]" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	//nothing to do here because of const variables
	_target = other._target;
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (isSigned() == false)
		throw (AForm::ExecutionNotSignedException());
	if (executor.getGrade() > getGradeExec())
		throw (AForm::ExecutionLowGradeException());

	std::cout << "brzZzzzzZZZvvvZZZzzzZZZ *imagine these are drilling noises*" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "Whoopsie! It's not like " << getTarget() << "'s brain needed robotomizing anyway. No refunds!" << std::endl;
	else
		std::cout << "Congrats! " << getTarget() << "'s brain will now surely work better. No hysteria guaranteed!" << std::endl;
}