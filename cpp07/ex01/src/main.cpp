/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 14:48:44 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main(void)
{
	std::cout << "+1 ON INTS" << std::endl;
	std::cout << "----------" << std::endl;
	int arrInt[] = {0, -1, -2, 999};
	iter(arrInt, sizeof(arrInt) / sizeof(int), plusOne);
	std::cout << std::endl;

	std::cout << "+1 ON FLOATS" << std::endl;
	std::cout << "----------" << std::endl;
	float arrFlt[] = {0.42f, -1.42f, -2.42f, 999.42f};
	iter(arrFlt, sizeof(arrFlt) / sizeof(float), plusOne);
	std::cout << std::endl;

	std::cout << "PRINT ON STRINGS" << std::endl;
	std::cout << "----------" << std::endl;
	std::string strs[] = {"Fear", "is", "the", "mind-killer"};
	iter(strs, 4, print);
	std::cout << std::endl;
}