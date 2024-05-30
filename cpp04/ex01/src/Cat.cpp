/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:11:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 12:10:30 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

// CONSTRUCTION & DESTRUCTION

Cat::Cat()
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "[Cat CONSTRUCTOR]" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "[Cat DESTRUCTOR]" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "[Cat COPY CONSTRUCTOR]" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other); // Copy base class parts
		delete brain; // Deallocate previously allocated memory
		brain = new Brain(*other.brain); // Allocate new memory and copy
	}
	std::cout << "[Cat COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

// MEMBER FUNCTIONS

void	Cat::makeSound() const
{
	std::cout << "🐈 meow mňau" << std::endl;
}

const std::string&	Cat::getType() const
{
	return (this->type);
}