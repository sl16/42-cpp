/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:36:37 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 12:40:53 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Base.hpp"
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"

#include <cstdlib>
#include <ctime>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);