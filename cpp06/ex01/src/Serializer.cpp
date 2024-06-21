/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 10:49:09 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

// CONSTRUCTORS AND DESTRUCTORS

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer &other)
{
	(void) other;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	(void) other;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}


Data*		Serializer::deserialize(uintptr_t raw)
{
	Data *ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}