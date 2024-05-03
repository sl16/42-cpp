/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:54:52 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/03 14:12:45 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	brain;
	std::string	*stringPTR;
	
	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;
	std::string	&stringREF = brain;
	
	std::cout << "Memory address held by string:\t\t" << &brain << std::endl;
	std::cout << "Memory address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value held by string:\t\t\t" << brain << std::endl;
	std::cout << "Value held by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value held by stringREF:\t\t" << stringREF << std::endl;
	
	return (0);	
}