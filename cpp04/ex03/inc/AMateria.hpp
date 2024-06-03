/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:19:56 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/03 12:17:47 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "./ICharacter.hpp"

class AMateria
{
	protected:
		const std::string type;
		
	public:
		AMateria();
		AMateria(std::string const & type);
		~AMateria();
		AMateria(const AMateria &other);
		AMateria& operator=(const AMateria &other);
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
};