/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:12 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/02 14:29:13 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/utils.hpp"

bool isAllNumeric(std::string input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isdigit(*i))
			return (false);
	}
	return (true);
}

bool isAllAlphabetic(std::string input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isalpha(*i) && !std::isspace(*i))
			return (false);
	}
	return (true);
}

bool isAlphanumeric(std::string input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isalnum(*i) && !std::isspace(*i))
			return (false);
	}
	return (true);
}

bool isAllSpaces(std::string input)
{
	for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
	{
		if (!std::isspace(*i))
			return (false);
	}
	return (true);
}