/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:53:42 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/08 22:36:27 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char **argv)
{
	std::string level;
	Harl harlFiltered;
	
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl << std::endl;
		std::cout << "Levels: debug, info, warning, error" << std::endl;
		return (1);
	}
	level = argv[1];
	harlFiltered.complain(level);

	return (0);
}