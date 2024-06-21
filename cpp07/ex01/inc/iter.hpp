/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:59 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 14:48:35 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void	plusOne(T& a)
{
	a++;
	std::cout << a << std::endl;
}

template <typename T>
void	print(T& a)
{
	std::cout << a << " ";
}

template <typename T>
void	iter(T *arr, size_t len, void(*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}