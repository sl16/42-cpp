/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:39:23 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/10 11:53:17 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	this->_name = name;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	this->_weapon = &newWeapon;
	return ;
}