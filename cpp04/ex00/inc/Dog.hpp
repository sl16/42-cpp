/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:10:47 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/29 18:27:38 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>

#include "./Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		void	makeSound() const;
		const std::string	&getType() const;
};


#endif