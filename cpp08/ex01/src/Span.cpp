/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 08:45:25 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/22 10:18:56 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(): _maxSize(0)
{
	return ;
}

Span::Span(unsigned int N): _maxSize(N)
{
	_arr.reserve(N);
	return ;
}

Span::~Span()
{
	return ;

}

Span::Span(const Span& other)
{
	_arr = other._arr;
	_maxSize = other._maxSize;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_arr = other._arr;
		_maxSize = other._maxSize;
	}
	return (*this);
}

void 	Span::addNumber(int num)
{
	if (getActualSize() >= getMaxSize())
		throw std::runtime_error("Array is full");
	_arr.push_back(num);
}

size_t	Span::getActualSize(void)
{
	return (_arr.size());
}

size_t	Span::getMaxSize(void)
{
	return (_maxSize);
}

void	Span::printArr(void)
{
	std::cout << "array content: ";
	for (std::vector<int>::iterator it = _arr.begin(); it != _arr.end(); ++it)
		std::cout << *it << ' ';
}

int		Span::shortestSpan(void)
{
	if (getActualSize() < 2)
		throw std::runtime_error("Requires at least 2 numbers in span");

	int span = INT_MAX;

	for (std::vector<int>::iterator bigLoop = _arr.begin(); bigLoop != _arr.end() - 1; ++bigLoop)
	{
		for (std::vector<int>::iterator smallLoop = bigLoop + 1; smallLoop != _arr.end(); ++smallLoop)
		{
			int currentSpan = abs(*bigLoop - *smallLoop);
			if (currentSpan < span)
			{
				span = currentSpan;
			}
		}
	}
	return (span);
}

int		Span::longestSpan(void)
{
	if (getActualSize() < 2)
		throw std::runtime_error("Requires at least 2 numbers in span");

	int minElement = *std::min_element(_arr.begin(), _arr.end());
	int maxElement = *std::max_element(_arr.begin(), _arr.end());

	return (maxElement - minElement);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; ++it)
	{
		addNumber(*it);
	}
}