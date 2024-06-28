/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:12:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/28 11:11:37 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error: wrong input (usage: ./PmergeMe <int1> <int2> ... <intN>)");

		PmergeMe algo;
		
		algo.parseInput(argv);
		algo.printBefore();
		algo.sortDeque();
		std::cout << "----------" << std::endl;
		algo.printBefore();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}