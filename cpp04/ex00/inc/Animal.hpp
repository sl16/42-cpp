/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:10:47 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 13:49:01 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual void				makeSound() const;
		virtual const std::string	&getType() const;
	
	protected:
		std::string type;
};


#endif