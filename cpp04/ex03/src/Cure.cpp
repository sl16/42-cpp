/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:26:22 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/02 17:07:14 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(std::string const & type): type(type)
{
	
}

Cure::~Cure()
{

}

Cure::Cure(const Cure &other): AMateria(other.type)
{
	*this = other;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
		// nothing to copy since attributes are const
	return (*this);
}

std::string const & Cure::getType() const
{
	return (this->type);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* Cure class cannot do anything *" << std::endl;
}