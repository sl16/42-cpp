/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/22 10:25:51 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main( void )
{
	srand(time(0));
	{
		try
		{
			std::cout << "DEFAULT TEST" << std::endl;
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			sp.printArr();
			std::cout << std::endl << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl << std::endl;
	{
		try
		{
			std::cout << "ARRAY FULL ERROR" << std::endl;
			Span sp = Span(3);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);

			sp.printArr();

			std::cout << std::endl << std::endl;
			
			sp.addNumber(9);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl << std::endl;
	{
		try
		{
			std::cout << "SPAN FUNCTIONS NOT POSSIBLE ERROR" << std::endl;
			Span sp = Span(3);

			// sp.addNumber(6);

			sp.printArr();

			std::cout << std::endl << std::endl;
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl << std::endl;
	{
		try
		{
			std::cout << "10 000 ARRAY MEMBERS" << std::endl;
			
			std::vector<int> arr;
			for (int i = 0; i < 10000; ++i)
				arr.push_back(rand() % 10000);

			Span sp(arr.size());
			sp.addRange(arr.begin(), arr.end());

			// sp.printArr();

			std::cout << std::endl << std::endl;
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}