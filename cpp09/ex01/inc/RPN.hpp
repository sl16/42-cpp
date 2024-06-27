/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:25:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/27 11:52:28 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cctype>
#include <limits>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		const RPN& operator=(const RPN& other);

		void validateInput(std::string& input);
		void calculateRes(std::string& input);

	private:
		std::stack<long long> _res;
		
};