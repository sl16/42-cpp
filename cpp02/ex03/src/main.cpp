/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:16:38 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/16 10:06:27 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

void testBsp(Point a, Point b, Point c, Point target)
{
    static int i = 1;

	std::cout << "-------------------" << std::endl;
	std::cout << "TEST " << i++ << std::endl;
	std::cout << "a, b, c, target: " << a << b << c << target << std::endl;
	
	if (bsp(a, b, c, target))
        std::cout << "bsp test PASSED." << std::endl;
    else
        std::cout << "bsp test FAILED." << std::endl;
}

int main()
{
    testBsp(Point(20,6), Point(10,2), Point(13,1), Point(-5,-20));
	testBsp(Point(0,0), Point(0,1), Point(1,0), Point(0.5f,0.5f));
    testBsp(Point(1,1), Point(2,3), Point(4,5), Point(2.5f,3.5f));
    testBsp(Point(3,3), Point(4,5), Point(6,7), Point(5.0f,6.0f));

	testBsp(Point(7,7), Point(8,9), Point(10,11), Point(-6.0f,-6.0f));
    testBsp(Point(9,9), Point(10,11), Point(12,13), Point(8.0f,8.0f));
    testBsp(Point(11,11), Point(12,13), Point(14,15), Point(10.0f,10.0f));
    testBsp(Point(13,13), Point(14,15), Point(16,17), Point(120.0f,12.0f));

    return 0;
}