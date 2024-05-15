/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:16:38 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/15 09:06:50 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main( void )
{
	{
		Fixed a(2);
		Fixed b(0.42f);
		Fixed c(a);
		
		std::cout << "________________" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		std::cout << "C: " << c << std::endl << std::endl;
		std::cout << "ARITHMETIC OPERATIONS:" << std::endl;
		std::cout << "A + B:\t" << a + b << std::endl;
		std::cout << "A - B:\t" << a - b << std::endl;
		std::cout << "A * B:\t" << a * b << std::endl;
		std::cout << "A / B:\t" << a / b << std::endl << std::endl;
		std::cout << "COMPARISON OPERATIONS:" << std::endl;
		std::cout << "A > B:\t" << (a > b) << std::endl;
		std::cout << "A < B:\t" << (a < b) << std::endl;
		std::cout << "A <= B:\t" << (a <= b) << std::endl;
		std::cout << "A <= C:\t" << (a <= c) << std::endl;
		std::cout << "A >= B:\t" << (a >= b) << std::endl;
		std::cout << "A >= C:\t" << (a >= c) << std::endl;
		std::cout << "A == B:\t" << (a == b) << std::endl;
		std::cout << "A == C:\t" << (a == c) << std::endl;
		std::cout << "A != B:\t" << (a != b) << std::endl;
		std::cout << "A != C:\t" << (a != c) << std::endl << std::endl;
		std::cout << "INCREMENTATION/DECREMENTATION OPERATIONS:" << std::endl;
		std::cout << "A, ++A:\t" << a << ", " << ++a << std::endl;
		std::cout << "A, A++:\t" << a << ", " << a++ << std::endl;
		std::cout << "A, --A:\t" << a << ", " << --a << std::endl;
		std::cout << "A, A--:\t" << a << ", " << a-- << std::endl;
		std::cout << "A:\t" << a << std::endl << std::endl;
		std::cout << "MEMBER FUNCTIONS:" << std::endl;
		std::cout << "min(" << a << ", " << b << "):\t" << a.min(a, b) << std::endl;
		std::cout << "max(" << a << ", " << b << "):\t" << a.max(a, b) << std::endl;
		const Fixed d(5);
		const Fixed e(69.69f);
		std::cout << "const D: " << d << std::endl;
		std::cout << "const E: " << e << std::endl;
		std::cout << "min(" << d << ",	 " << e << "):\t" << d.min(d, e) << std::endl;
		std::cout << "max(" << d << ", " << e << "):\t" << d.max(d, e) << std::endl;
		std::cout << "________________" << std::endl << std::endl;
	}
	{
		std::cout << "PROVIDED TESTS:" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	return (0);
}