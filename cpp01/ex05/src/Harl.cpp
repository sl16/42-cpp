/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:52:15 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/08 22:03:28 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

void Harl::_debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
	
void Harl::_info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	//initialized without typedef
	void (Harl::*debug)() = &Harl::_debug;
	//initialized with typedef
    funcPtr info = &Harl::_info;
    funcPtr warning = &Harl::_warning;
    funcPtr error = &Harl::_error;

	funcPtr funcArr[4] = {debug, info, warning, error};
	std::string levels[4] = {"debug", "info", "warning", "error"};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*funcArr[i])();
	}
}