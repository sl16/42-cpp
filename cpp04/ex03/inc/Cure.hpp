/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:21:28 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/03 12:35:00 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AMateria.hpp"

class Cure : protected AMateria
{
	public:
		Cure();
		Cure(std::string const & type);
		~Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		
		Cure*	clone() const;
		void 	use(ICharacter& target);
};