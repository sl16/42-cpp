/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:19:55 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/04 11:00:23 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	inputParser(int argc, char **argv)
{
	std::fstream tryFile;
	// CHECK FOR CORRECT NUMBER OF ARGUMENTS
	if (argc != 4)
	{
		std::cout << "Correct usage: ./find_and_replace <filename> <string to replace> <replacement string>" << std::endl;
		std::exit(1);
	}
	// CHECK IF PROVIDED FILE IS READABLE
	tryFile.open(argv[1], std::ios::in);
	if (!tryFile)
	{
		std::cout << "Error: File " << argv[1] << " cannot be opened for reading." << std::endl;
		std::exit(1);
	}
	tryFile.close();
	
	return (0);
}

// std::find() to find the string?, erase() in the range, then insert()

int main(int argc, char **argv)
{
	std::string file;
	std::string s1;
	std::string s2;
	std::string line;

	inputParser(argc, argv);
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	

	return (0);
}