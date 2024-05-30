/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:11:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 12:10:30 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

// CONSTRUCTION & DESTRUCTION

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "[WrongCat CONSTRUCTOR]" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat DESTRUCTOR]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	*this = other;
	std::cout << "[WrongCat COPY CONSTRUCTOR]" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		*this = other;
	std::cout << "[WrongCat COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

// MEMBER FUNCTIONS

// void	WrongCat::makeSound() const
// {
// 	std::cout << "🐈 meow mňau" << std::endl;
// }

const std::string&	WrongCat::getType() const
{
	return (this->type);
}