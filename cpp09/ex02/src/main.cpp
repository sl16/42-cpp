/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:12:19 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/29 14:48:40 by vbartos          ###   ########.fr       */
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
		algo.printOrder("before");
		std::clock_t start = std::clock();
		algo.sortDeque();
		std::clock_t end = std::clock();
		std::cout << "----------" << std::endl;
		algo.printOrder("after");
		std::cout << "----------" << std::endl;
		algo.printTime(start, end);
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}