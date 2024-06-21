/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 16:41:56 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main(void)
{
	{
		std::cout << "INTS - DEFAULT ARRAY CONSTRUCTION" << std::endl;
		std::cout << "--------------------------" << std::endl;
		Array<int> arr_int_default;
		std::cout << "arr size: " << arr_int_default.size() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "STRINGS - NON-DEFAULT ARRAY CONSTRUCTION" << std::endl;
		std::cout << "--------------------------" << std::endl;
		Array<std::string> arr_strs(3);
		std::cout << "arr size: " << arr_strs.size() << std::endl;
		arr_strs.print();
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "FLOATS - NON-DEFAULT ARRAY COPY CONSTRUCTION" << std::endl;
		std::cout << "--------------------------" << std::endl;
		Array<float> arr_floats(11);
		arr_floats[5] = 42.42f;
		std::cout << "arr size: " << arr_floats.size() << std::endl;
		arr_floats.print();

		std::cout << "*creating another array via copy construction*" << std::endl;
		Array<float> arr_floats_copy(arr_floats);
		std::cout << "arr copy size: " << arr_floats_copy.size() << std::endl;
		arr_floats_copy.print();

		std::cout << "*creating another array via copy assignment*" << std::endl;
		Array<float> arr_floats_copy2 = arr_floats;
		std::cout << "arr copy2 size: " << arr_floats_copy2.size() << std::endl;
		arr_floats_copy2.print();
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "DOUBLES - NON-DEFAULT ARRAY CONSTRUCTION" << std::endl;
		std::cout << "--------------------------" << std::endl;
		Array<double> arr_doubles(5);
		std::cout << "arr size: " << arr_doubles.size() << std::endl;
		arr_doubles.print();

		std::cout << "*changing the last member to '42.42'*" << std::endl;
		arr_doubles[4] = 42.42;
		arr_doubles.print();
		
		std::cout << "*attempting to access index out of bounds*" << std::endl;
		try
		{
			arr_doubles[-1];
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		try
		{
			arr_doubles[10000];
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}