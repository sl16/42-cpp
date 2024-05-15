/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:18:54 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/15 14:15:35 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

// CONSTRUCTION & DESTRUCTION

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[CONSTRUCTOR CALLED] " <<_name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[DESTRUCTOR CALLED] " <<_name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "[CONSTRUCTOR CALLED] " <<_name << " constructed from copy" << std::endl;
	
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "[ASSIGNMENT CALLED] " <<_name << " assigned" << std::endl;
	
	if (this != &other)
		*this = other;
	return (*this);
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0)
	{
		std::cout << "💀 ClapTrap " << _name << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (_ep > 0)
	{
		std::cout << "💥 ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
	}
	else
		std::cout << "😯 ClapTrap " << _name << " ran out of energy while attempting to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp > 0)
	{
		_hp -= amount;
		std::cout << "🤕 ClapTrap " << _name << " takes " << amount;
		std::cout << " points of damage (total HP: " << _hp << "). Ouch!" << std::endl;
	}
	else
		std::cout << "😭 RIP ClapTrap " << _name << ", you had a good run!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << "💀 ClapTrap " << _name << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (_ep > 0)
	{
		_hp += amount;
		std::cout << "🔋 ClapTrap " << _name << " repairs itself, getting ";
		std::cout << amount << " hit points back (total HP: " << _hp << ")!" << std::endl;
		_ep--;
	}
	else
		std::cout << "😯 ClapTrap " << _name << " ran out of energy while attempting to repair itself." << std::endl;
}