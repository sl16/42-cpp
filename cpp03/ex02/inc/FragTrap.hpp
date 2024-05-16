/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:25:37 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/16 14:26:48 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>

#include "./ClapTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif