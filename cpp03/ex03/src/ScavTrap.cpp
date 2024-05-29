/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:27:24 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/29 14:24:36 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

// CONSTRUCTION & DESTRUCTION

ScavTrap::ScavTrap(): ClapTrap()
{
	// this->_name = "N/A";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;

	std::cout << "[ScavTrap CONSTRUCTOR CALLED] " << getName() << " constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;

	std::cout << "[ScavTrap CONSTRUCTOR CALLED] " << getName() << " constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap DESTRUCTOR CALLED] " << getName() << " destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	*this = other;

	std::cout << "[ScavTrap CONSTRUCTOR CALLED] " << getName() << " constructed from copy" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{	
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}
	return (*this);

	std::cout << "[ScavTrap ASSIGNMENT CALLED] " << getName() << " assigned" << std::endl;
}

// MEMBER FUNCTIONS

void ScavTrap::guardGate(void)
{
	std::cout << "🛡️  " << getName() << " has entered gate keeper mode" << std::endl;
}



void ScavTrap::attack(const std::string& target)
{
	// std::cout << "remaining hp: " << this->_hp;
	if (this->_hp <= 0)
	{
		std::cout << "💀 " << getName() << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout << "💥 " << getName() << " spends 3 hours talking nonsense to " << target;
		std::cout << ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "😯 " << getName() << " ran out of energy while attempting to attack." << std::endl;
}

std::string ScavTrap::getName()
{
	return (this->_name);
}