/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:17:52 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/15 09:03:45 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		//CONSTRUCTORS		
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);

		//OPERATOR OVERLOADS
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		bool operator>(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);
		
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		//MEMBER FUNCTIONS
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
		
		static Fixed& min(Fixed& fp1, Fixed& fp2);
		static Fixed& max(Fixed& fp1, Fixed& fp2);
		const static Fixed& min(const Fixed& fp1, const Fixed& fp2);
		const static Fixed& max(const Fixed& fp1, const Fixed& fp2);
		
	private:
		int					_fpVal;
		const static int	_bits;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif