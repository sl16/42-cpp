/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:56:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/05 13:02:57 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat::Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(): _name(name), _grade(grade)
{
	
}

Bureaucrat::~Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		
	}
}

std::string const Bureaucrat::getName() const
{
	
}

int Bureaucrat::getGrade() const
{
	
}