/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:59 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/22 10:18:00 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <climits>
#include <algorithm>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void 	addNumber(int num);
		size_t	getActualSize(void);
		size_t	getMaxSize(void);
		void	printArr(void);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		
	private:
		std::vector<int> _arr;
		unsigned int	 _maxSize;
};