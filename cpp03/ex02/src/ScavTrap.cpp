/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:27:24 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/16 14:16:34 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

// CONSTRUCTION & DESTRUCTION

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "[ScavTrap CONSTRUCTOR CALLED] " << this->_name << " constructed" << std::endl;

	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap DESTRUCTOR CALLED] " << this->_name << " destroyed" << std::endl;
}

// MEMBER FUNCTIONS

void ScavTrap::guardGate(void)
{
	std::cout << "🛡️  " << this->_name << " has entered gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	// std::cout << "remaining hp: " << this->_hp;
	if (this->_hp <= 0)
	{
		std::cout << "💀 " << this->_name << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout << "💥 " << this->_name << " spends 3 hours talking nonsense to " << target;
		std::cout << ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "😯 " << this->_name << " ran out of energy while attempting to attack." << std::endl;
}