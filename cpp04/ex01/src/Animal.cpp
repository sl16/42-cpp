/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:11:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 14:56:19 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

// CONSTRUCTION & DESTRUCTION

Animal::Animal()
{
	this->type = "N/A";
	std::cout << "[ANIMAL CONSTRUCTOR]" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[ANIMAL DESTRUCTOR]" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "[ANIMAL COPY CONSTRUCTOR]" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "[ANIMAL COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

// MEMBER FUNCTIONS
void	Animal::makeSound() const
{
	std::cout << "👽 yo wazzup" << std::endl;
}

const std::string		&Animal::getType() const
{
	return (this->type);
}