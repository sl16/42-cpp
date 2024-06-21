/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 20:40:47 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main( void )
{
	{
		std::cout << "INT VECTOR" << std::endl; 
		int				 valueToFind;
		std::vector<int> vecInt;

		valueToFind = 4;
		vecInt.push_back(1);
		vecInt.push_back(2);
		vecInt.push_back(3);
		vecInt.push_back(4);
		vecInt.push_back(5);
		try
		{
			std::vector<int>::iterator iterInt = easyfind(vecInt, valueToFind);
			std::cout << "value " << valueToFind << " found at position " << std::distance(vecInt.begin(), iterInt) << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "------------" << std::endl; 
	{
		std::cout << "INT DEQUE" << std::endl; 
		int					valueToFind;
		std::deque<float>	dequeInt;

		valueToFind = 5;
		dequeInt.push_back(1);
		dequeInt.push_back(2);
		dequeInt.push_back(3);
		dequeInt.push_back(4);
		dequeInt.push_back(5);
		try
		{
			std::deque<float>::iterator iterInt = easyfind(dequeInt, valueToFind);
			std::cout << "value " << valueToFind << " found at position " << std::distance(dequeInt.begin(), iterInt) << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "------------" << std::endl; 
	{
		std::cout << "FLOAT LIST" << std::endl; 
		int					valueToFind;
		std::list<float>	listFloat;

		valueToFind = 1;
		listFloat.push_back(1);
		listFloat.push_back(2);
		listFloat.push_back(3);
		listFloat.push_back(4);
		listFloat.push_back(5);
		try
		{
			std::list<float>::iterator iterFloat = easyfind(listFloat, valueToFind);
			std::cout << "value " << valueToFind << " found at position " << std::distance(listFloat.begin(), iterFloat) << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "------------" << std::endl; 
	{
		std::cout << "FLOAT LIST - THROW EXCEPTION" << std::endl; 
		int					valueToFind;
		std::list<float>	listFloat;

		valueToFind = 0;
		listFloat.push_back(1);
		listFloat.push_back(2);
		listFloat.push_back(3);
		listFloat.push_back(4);
		listFloat.push_back(5);
		try
		{
			std::list<float>::iterator iterFloat = easyfind(listFloat, valueToFind);
			std::cout << "value " << valueToFind << " found at position " << std::distance(listFloat.begin(), iterFloat) << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}