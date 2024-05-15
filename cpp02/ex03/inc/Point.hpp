/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:14 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/15 10:32:32 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "../inc/Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		~Point();
		Point(const Point &other);
		Point& operator=(const Point &other);

	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif