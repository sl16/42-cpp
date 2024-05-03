/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:41:07 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 09:24:11 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "[CONSTRUCTOR] Zombie object constructed." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "[DESTRUCTOR] " << this->_name << " destroyed." << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void Zombie::setZombieName(std::string name)
{
	this->_name = name;
	return ;
}