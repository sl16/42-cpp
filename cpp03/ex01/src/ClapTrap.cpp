/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:18:54 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/20 13:06:09 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

// CONSTRUCTION & DESTRUCTION

ClapTrap::ClapTrap(): _name("N/A"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[ClapTrap CONSTRUCTOR CALLED] " <<_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[ClapTrap CONSTRUCTOR CALLED] " << this->_name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap DESTRUCTOR CALLED] " << this->_name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;

	std::cout << "[ClapTrap CONSTRUCTOR CALLED] " << _name << " constructed from copy" << std::endl;
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

	std::cout << "[ClapTrap ASSIGNMENT CALLED] " << this->_name << " assigned" << std::endl;
	
	return (*this);
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string& target)
{
	// std::cout << "remaining hp: " << this->_hp;
	if (this->_hp <= 0)
	{
		std::cout << "💀 " << this->_name << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout << "💥 " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "😯 " << this->_name << " ran out of energy while attempting to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		this->_hp -= amount;
		std::cout << "🤕 " << this->_name << " takes " << amount;
		std::cout << " points of damage (total HP: " << this->_hp << "). Ouch!" << std::endl;
	}
	else
	{
		this->_hp = 0;
		std::cout << "😭 RIP " << this->_name << ", you had a good run!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "💀 " << this->_name << " can't do shit, he's already dead!" << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		_hp += amount;
		std::cout << "🔋 " << this->_name << " repairs itself, getting ";
		std::cout << amount << " hit points back (total HP: " << this->_hp << ")!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "😯 " << this->_name << " ran out of energy while attempting to repair itself." << std::endl;
}