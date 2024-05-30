/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:11:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 14:28:39 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

// CONSTRUCTION & DESTRUCTION

Dog::Dog()
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "[Dog CONSTRUCTOR]" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "[Dog DESTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "[Dog COPY CONSTRUCTOR]" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other); // Copy base class parts
		delete brain; // Deallocate previously allocated memory
		brain = new Brain(*other.brain); // Allocate new memory and copy
	}
	std::cout << "[Dog COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

// MEMBER FUNCTIONS

void	Dog::makeSound() const
{
	std::cout << "🐶 woofity woof" << std::endl;
}

const std::string&	Dog::getType() const
{
	return (this->type);
}