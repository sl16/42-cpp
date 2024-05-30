/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:11:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 12:58:56 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

// CONSTRUCTION & DESTRUCTION

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "[Dog CONSTRUCTOR]" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog DESTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
	*this = other;
	std::cout << "[Dog COPY CONSTRUCTOR]" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		*this = other;
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