/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:16:38 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/20 13:13:51 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main( void )
{
	{
		std::cout << MAGENTA << "CLAPTRAP TESTS" << RESET << std::endl << std::endl;
		
		ClapTrap ct1("CL4P-TP");
		
		ct1.attack("big ass monster");
		ct1.takeDamage(3);
		ct1.takeDamage(3);
		for (int i = 0; i < 4; i++)
			ct1.beRepaired(2);
		ct1.attack("another big ass monster");
		for (int i = 0; i < 6; i++)
			ct1.takeDamage(3);
		ct1.attack("big ass monster");
	}
	std::cout << std::endl << "-----------" << std::endl << std::endl;
	{
		std::cout << MAGENTA << "SCAVTRAP TESTS" << RESET << std::endl << std::endl;

		ScavTrap st1("Scavvie");

		st1.attack("Handsome Jack");
		st1.takeDamage(49);
		st1.guardGate();
		for (int i = 0; i < 2; i++)
			st1.beRepaired(10);
		st1.attack("Handsome Jack");
		for (int i = 0; i < 5; i++)
			st1.takeDamage(23);
		st1.attack("Handsome Jack");
	}
	std::cout << std::endl << "-----------" << std::endl << std::endl;
	{
		std::cout << MAGENTA << "FRAGTRAP TESTS" << RESET << std::endl << std::endl;

		FragTrap ft1("Fragster");
		// FragTrap ft2(ft1);

		ft1.attack("their nemesis");
		ft1.takeDamage(69);
		ft1.highFivesGuys();
		for (int i = 0; i < 2; i++)
			ft1.beRepaired(10);
		ft1.attack("their nemesis");
		for (int i = 0; i < 5; i++)
			ft1.takeDamage(23);
		ft1.attack("their nemesis");
	}
	return (0);	
}