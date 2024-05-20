/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:17:52 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/20 17:49:21 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include <iostream>

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

class DiamondTrap: public ScavTrap, public FragTrap 
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap& operator=(const DiamondTrap &other);

		void attack(const std::string& target);
		void whoAmI();
		std::string getName();

	private:
		std::string	_name;
};


#endif