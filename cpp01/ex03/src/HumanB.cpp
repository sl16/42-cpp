/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:39:23 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 14:52:53 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
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
	std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon newWeapon)
{
	this->_weapon = newWeapon;
	return ;
}