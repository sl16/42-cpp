/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:25:34 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/20 17:50:33 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

// CONSTRUCTION & DESTRUCTION

FragTrap::FragTrap(): ClapTrap()
{
	this->_name = "N/A";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;

	std::cout << "[FragTrap CONSTRUCTOR CALLED] " << getName() << " constructed" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;

	std::cout << "[FragTrap CONSTRUCTOR CALLED] " << getName() << " constructed" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap DESTRUCTOR CALLED] " << getName() << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	*this=other;
	
	std::cout << "[FragTrap CONSTRUCTOR CALLED] " << getName() << " constructed from copy" << std::endl;

}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}

	std::cout << "[FragTrap ASSIGNMENT CALLED] " << getName() << " assigned" << std::endl;

	return (*this);
}

// MEMBER FUNCTIONS

void FragTrap::highFivesGuys(void)
{
	std::cout << "🖐️  " << getName() << " attempts to highfive everyone. Noone responds." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	// std::cout << "remaining hp: " << this->_hp;
	if (this->_hp <= 0)
	{
		std::cout << "💀 " << getName() << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout << "💥 " << getName() << " tried to highfive " << target;
		std::cout << ", but missed and smacked their face instead. This resulted in " << this->_ad << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "😯 " << getName() << " ran out of energy while attempting to attack." << std::endl;
}

std::string FragTrap::getName()
{
	return (this->_name);
}