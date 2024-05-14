/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:18:54 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/14 10:41:45 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::_bits = 8;

// CONSTRUCTORS

Fixed::Fixed()
{
	this->_fpVal = 0;
	
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Constructs a Fixed object with an integer value.
 * 
 * This constructor takes an integer value and initializes the Fixed object with it.
 * The integer value is converted to a fixed-point representation using bitwise left shift.
 * 
 * For each left shift, the decimal number is doubled. Hence, the nominal value
 * will not be representative of the original decimal value, since it is now in the
 * fixed-point number system, but still stored in a decimal notation. For example,
 * if we construct the object with '5', it will be doubled 8 times (since we have 
 * 8 fractional bits), or effectively multiplied by 256, giving us 1280.
 * 
 * In order to retrieve the actual decimal number now represented in the fixed-point system,
 * we have to look at the binary value complemented by the fixed point denoted
 * by the number of bits, in this case 8. Since we were originally provided an integer,
 * the fractional part will equal to '00000000', or 0 in decimal.
 * 
 * @param num The integer value to be stored in the Fixed object.
 */
Fixed::Fixed(const int num)
{
	this->_fpVal = num << _bits;
	
	std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief Constructs a new Fixed object from a floating-point number.
 * 
 * This constructor takes a floating-point number as input and converts it to a fixed-point representation.
 * The floating-point number is multiplied by 2 raised to the number of fractional bits (stored in `_bits`)
 * and then rounded to the nearest integer value. The resulting integer value is stored in `_fpVal`.
 * 
 * For a detailed explanation of the bitshifting logic, refer to the comment above.
 * The reasoning for using '1 << _bits' to multiply the number is because here,
 * the provided number is a float, and bitshifting operators are not well-defined
 * for floating-point numbers in C++. Therefore, the multiplication must be used
 * to prevent compile errors.
 * 
 * @param num The floating-point number to be converted to fixed-point representation.
 */
Fixed::Fixed(const float num)
{
	this->_fpVal = static_cast<int>(roundf(num * (1 << _bits)));
	
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	// this->_fpVal = other.getRawBits();
	*this = other;
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

/**
 * @brief Overloaded stream insertion operator for Fixed class.
 * 
 * This function allows the Fixed object to be printed using the insertion operator (<<).
 * It converts the Fixed object to a float and then prints it to the output stream.
 * 
 * @param out The output stream to write to.
 * @param fixed The Fixed object to be printed.
 * @return std::ostream& The output stream after writing the Fixed object.
 */
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// MEMBER FUNCTIONS

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_fpVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpVal = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fpVal) / static_cast<float>(1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (this->_fpVal >> _bits);
}