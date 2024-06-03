/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:26:22 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/03 12:35:02 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure()
{

}

Cure::Cure(std::string const & type): AMateria(type)
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

Cure* Cure::clone() const
{
	Cure *cloned = new Cure(*this);
	return (cloned);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << "'s wounds *"<< std::endl;
}