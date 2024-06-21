/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:59 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 16:40:38 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);

		size_t	size() const;
		void	print() const;

	private:
		T*		_arr;
		size_t	_arrLen;
};

template <typename T>
Array<T>::Array()
{
	_arr = NULL;
	_arrLen = 0;
	std::cout << "[DEFAULT CONSTRUCTION]" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_arr = new T[n];
	_arrLen = n;
	std::fill_n(_arr, n, T());
	std::cout << "[NON-DEFAULT CONSTRUCTION]" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
	std::cout << "[DESTRUCTION]" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_arrLen = other._arrLen;
	_arr = new T[_arrLen];
	for (size_t i = 0; i < _arrLen; i++)
		_arr[i] = other._arr[i];
	std::cout << "[COPY CONSTRUCTION]" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		_arrLen = other._arrLen;
		_arr = new T[_arrLen];
		for (size_t i = 0; i < _arrLen; i++)
			_arr[i] = other._arr[i];
	}
	std::cout << "[COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

template <typename T>
size_t Array<T>::size() const
{
	return (_arrLen);
}

template <typename T>
void Array<T>::print() const
{
	std::cout << "arr members: ";
	for (size_t i = 0; i < _arrLen; i++)
		std::cout << _arr[i] << " ";
	std::cout << std::endl;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if(index >= _arrLen)
		throw std::exception();
	return (_arr[index]);
}