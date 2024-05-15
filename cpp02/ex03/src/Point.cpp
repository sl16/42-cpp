/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:07 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/15 12:03:15 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

// CONSTRUCTORS

Point::Point():_x(0), _y(0)
{

}

Point::Point(const Fixed x, const Fixed y):_x(x), _y(y)
{

}

Point::~Point()
{

}

Point::Point(const Point &other)
{
	*this = other;
}

Point& Point::operator=(const Point &other)
{
	// POINT OBJECT'S MEMBER VARIABLES ARE CONST, THEREFORE WE CANNOT REASSIGN THEM
	return (*this);
}