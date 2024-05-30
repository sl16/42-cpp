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
	std::cout << "[Cat CONSTRUCTOR]" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat DESTRUCTOR]" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
	*this = other;
	std::cout << "[Cat COPY CONSTRUCTOR]" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		type = other.type;
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