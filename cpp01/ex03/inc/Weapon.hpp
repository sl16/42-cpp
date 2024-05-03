/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:18:27 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 15:04:18 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(std::string initialType);
		~Weapon();

		std::string getType(void) const;
		void		setType(std::string newType);
	
	private:
		std::string	_type;
};

#endif