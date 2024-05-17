/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:15:46 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/17 22:49:35 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>

#include "./ClapTrap.hpp"

class ScavTrap:public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate(void);
};

#endif