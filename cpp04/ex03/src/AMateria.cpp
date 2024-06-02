/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:26:12 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/02 16:58:42 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type)
{

}

AMateria::~AMateria()
{

}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		// nothing to copy since attributes are const
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria class cannot do anything *" << std::endl;
}