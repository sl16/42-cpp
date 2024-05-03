/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:41:23 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 09:08:46 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
	Zombie *heapZombie;
	Zombie *heapZombie2;
	
	heapZombie = newZombie("Heapster");
	heapZombie->announce();
	randomChump("Ser Stackington");

	heapZombie2 = newZombie("Heapster Junior");
	heapZombie2->announce();

	randomChump("Ser Stackington the II");
	
	delete(heapZombie);
	delete(heapZombie2);
	return (0);
}