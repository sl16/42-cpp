/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:49:59 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/17 18:56:12 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <string>

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
};

struct Data
{
	int		a;
	float	b;
	double	c;
};