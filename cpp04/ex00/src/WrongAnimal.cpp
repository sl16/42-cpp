/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:11:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 13:11:17 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

// CONSTRUCTION & DESTRUCTION

WrongAnimal::WrongAnimal()
{
	this->type = "N/A";
	std::cout << "[WrongAnimal CONSTRUCTOR]" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal DESTRUCTOR]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "[WrongAnimal COPY CONSTRUCTOR]" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		*this = other;
	std::cout << "[WrongAnimal COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

// MEMBER FUNCTIONS
void	WrongAnimal::makeSound() const
{
	std::cout << "👽 yo wazzup" << std::endl;
}

const std::string		&WrongAnimal::getType() const
{
	return (this->type);
}