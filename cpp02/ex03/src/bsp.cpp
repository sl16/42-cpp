/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:03:48 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/16 10:05:34 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include <cmath>

// This solution follows the barycentric coordinate system, which I found
// the easiest to grasp and implement.

Fixed	getArea(Point const point, Point const p1, Point const p2)
{
	Fixed area;
	
	area = (point.get_X() * (p1.get_Y() - p2.get_Y()) + p1.get_X() * (p2.get_Y()
			- point.get_Y()) + p2.get_X() * (point.get_Y() - p1.get_Y())) / 2.0f;
	area = abs(area.toInt());

	return (area);
}

/**
 * Checks if a point is inside a triangle using the barycentric coordinate system.
 * 
 * In a Barycentric coordinate system, every point inside a triangle can be
 * represented as a weighted average of its three vertices. 
 *
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to check.
 * @return True if the point is inside the triangle, false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea;
	Fixed	a1;
	Fixed	a2;
	Fixed	a3;

	totalArea = getArea(a, b, c);
	a1 = getArea(point, a, b);
	a2 = getArea(point, b, c);
	a3 = getArea(point, a, c);

	// std::cout << "Total area: " << totalArea << std::endl;
	// std::cout << "A1: " << a1 << std::endl;
	// std::cout << "A2: " << a2 << std::endl;
	// std::cout << "A3: " << a3 << std::endl;

	if (totalArea == a1 + a2 + a3)
		return (true);
	else
		return (false);
}