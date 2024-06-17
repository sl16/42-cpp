/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/17 18:45:32 by vbartos          ###   ########.fr       */
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

