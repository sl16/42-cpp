/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:19:55 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/08 21:08:58 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int	inputParser(int argc, char **argv)
{
	std::fstream tryFile;
	std::string oldStr;
	
	if (argc != 4)
	{
		std::cout << "Correct usage: ./find_and_replace <filename> <string to replace> <replacement string>" << std::endl;
		std::exit(1);
	}
	oldStr = argv[2];
	if (oldStr == "")
	{
		std::cout << "Error: You must specify a string to be replaced." << std::endl;
		std::exit(1);
	}
	tryFile.open(argv[1], std::ios::in);
	if (tryFile.fail())
	{
		std::cout << "Error: File " << argv[1] << " cannot be opened for reading." << std::endl;
		std::exit(1);
	}
	tryFile.close();
	
	return (0);
}

int	createOutfile(std::string fileStr, char *fileName)
{
	std::ofstream		outFile;
	std::string			outFileName;

	outFileName = std::string(fileName) + ".replace";
	outFile.open(outFileName.c_str());
	if (outFile.fail())
	{
		std::cout << "Error: File " << outFileName << " cannot be opened for writing." << std::endl;
		std::exit(1);
	}
	outFile << fileStr;
	outFile.close();
	std::cout << "Success: File " << outFileName << " created." << std::endl;
	
	return (0);
}

int	findAndReplace(std::string fileStr, std::string oldStr, std::string newStr, char *fileName)
{
	std::size_t pos;
	std::size_t len;

	pos = fileStr.find(oldStr);
	len = oldStr.length();
	while (pos != std::string::npos)
	{
		fileStr.erase(pos, len);
		fileStr.insert(pos, newStr);
		pos = fileStr.find(oldStr);
	}
	createOutfile(fileStr, fileName);

	return (0);
}

int main(int argc, char **argv)
{
	std::string			oldStr;
	std::string			newStr;
	std::string			fileStr;
	std::ifstream		inFile;
	std::stringstream	buffer;
	

	inputParser(argc, argv);
	oldStr = argv[2];
	newStr = argv[3];

	inFile.open(argv[1]);
	buffer << inFile.rdbuf();
	inFile.close();
	fileStr = buffer.str();

	findAndReplace(fileStr, oldStr, newStr, argv[1]);

	return (0);
}