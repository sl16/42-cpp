/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:16:38 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/20 13:01:15 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main( void )
{
	ClapTrap ct1("CL4P-TP");
	ClapTrap ct2(ct1);
	ClapTrap ct3 = ct2;
	
	ct1.attack("big ass monster");
	ct1.takeDamage(3);
	ct1.takeDamage(3);
	for (int i = 0; i < 4; i++)
		ct1.beRepaired(2);
	ct1.attack("another big ass monster");
	for (int i = 0; i < 6; i++)
		ct1.takeDamage(3);
	ct1.attack("big ass monster");

	return (0);	
}