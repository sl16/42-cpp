/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:19:55 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 17:49:38 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	inputParser(int argc, char **argv)
{
	std::fstream file;
	
	if (argc != 4)
	{
		std::cout << "Correct usage: ./find_and_replace <filename> <string to replace> <replacement string>" << std::endl;
		std::exit(1);
	}
	
}

// std::find() to find the string?, erase() in the range, then insert()

int main(int argc, char **argv)
{
	std::string file;
	std::string s1;
	std::string s2;

	inputParser(argc, argv);
	

	return (0);
}