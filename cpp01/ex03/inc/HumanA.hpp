/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:18:24 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 14:43:24 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>

#include "./Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon weaponType);
		~HumanA();
		
		void attack(void);

	private:
		std::string _name;
		Weapon		_weapon;
};

#endif