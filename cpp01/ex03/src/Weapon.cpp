/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:18:22 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 15:04:37 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string initialType)
{
	this->_type = initialType;
	
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string Weapon::getType(void) const
{
	return(this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
	return ;
}