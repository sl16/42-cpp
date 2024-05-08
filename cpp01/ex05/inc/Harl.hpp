/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:54:47 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/08 22:03:50 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Harl
{
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);

public:
	void complain(std::string level);
};

typedef void(Harl::*funcPtr)(void);