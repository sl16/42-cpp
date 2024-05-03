/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:39:24 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 14:52:36 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>

#include "./Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		
		void attack(void);
		void setWeapon(Weapon newWeapon);

	private:
		std::string _name;
		Weapon		_weapon;
};

#endif