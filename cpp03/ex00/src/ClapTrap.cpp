/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:18:54 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/20 13:02:01 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

// CONSTRUCTION & DESTRUCTION

ClapTrap::ClapTrap(): _name("N/A"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[CONSTRUCTOR CALLED] " <<_name << " constructed" << std::endl;
}

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
	*this = other;

	std::cout << "[CONSTRUCTOR CALLED] " << _name << " constructed from copy" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}

	std::cout << "[ASSIGNMENT CALLED] " << this->_name << " assigned" << std::endl;
	
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
	{
		this->_hp = 0;
		std::cout << "😭 RIP ClapTrap " << _name << ", you had a good run!" << std::endl;
	}
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