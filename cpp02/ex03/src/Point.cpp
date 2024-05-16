/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:07 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/16 09:59:40 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

// CONSTRUCTORS

Point::Point():_x(0), _y(0)
{

}

Point::Point(const float x, const float y):_x(x), _y(y)
{

}

Point::~Point()
{

}

Point::Point(const Point &other):_x(other.get_X()), _y(other.get_Y())
{
	
}

Point& Point::operator=(const Point &/*other*/)
{
	// POINT OBJECT'S MEMBER VARIABLES ARE CONST, THEREFORE WE CANNOT REASSIGN THEM
	return (*this);
}

// MEMBER FUNCTIONS

const Fixed& Point::get_X(void) const
{
	return (_x);
}

const Fixed& Point::get_Y(void) const
{
	return (_y);
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.get_X() << ", " << point.get_Y() << ")";
	return (out);
}