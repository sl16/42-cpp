/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:14 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/16 09:56:46 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "../inc/Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &other);
		Point& operator=(const Point &other);

		const Fixed&	get_X(void) const;
		const Fixed&	get_Y(void) const;

	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream &out, const Point &point);

#endif