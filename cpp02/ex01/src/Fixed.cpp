/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:18:54 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/13 11:13:19 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed()
{
	this->_fpVal = 0;
	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_fpVal = num;
	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	this->_fpVal = static_cast<int>(roundf(num));
	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	this->_fpVal = other.getRawBits();
}

// OPERATOR OVERLOADS

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_fpVal = other.getRawBits();
	}
	return (*this);
}

// MEMBER FUNCTIONS

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_fpVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpVal = raw;
}