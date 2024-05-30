/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:43:51 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 14:39:14 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

// CONSTRUCTION & DESTRUCTION

Brain::Brain()
{
	std::cout << "[Brain CONSTRUCTOR]" << std::endl;
}

Brain::~Brain()
{
	std::cout << "[Brain DESTRUCTOR]" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "[Brain COPY CONSTRUCTOR]" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	std::cout << "[Brain COPY ASSIGNMENT]" << std::endl;
	return (*this);
}

// MEMBER FUNCTIONS