/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:25:34 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/29 14:29:33 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// CONSTRUCTION & DESTRUCTION

DiamondTrap::DiamondTrap(): ClapTrap("clp_N/A")
{
	this->_name = "dia_N/A";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;

	std::cout << "[DiamondTrap CONSTRUCTOR CALLED] " << getName() << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;

	std::cout << "[DiamondTrap CONSTRUCTOR CALLED] " << getName() << " constructed" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap DESTRUCTOR CALLED] " << getName() << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this=other;
	
	std::cout << "[DiamondTrap CONSTRUCTOR CALLED] " << getName() << " constructed from copy" << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}

	std::cout << "[DiamondTrap ASSIGNMENT CALLED] " << getName() << " assigned" << std::endl;

	return (*this);
}

// MEMBER FUNCTIONS

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "📋 " << getName() << " just found out from their grandparent " << ClapTrap::_name << " that they're adopted. Whoops!" << std::endl;
}

std::string DiamondTrap::getName()
{
	return (this->_name);
}