/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:25:30 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/27 11:52:28 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <list>
#include <limits>
#include <cstdio>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		const PmergeMe& operator=(const PmergeMe& other);

		void parseInput(char **argv);
		void printOrder(std::string when);
		void printTime(std::clock_t& start, std::clock_t& end);
		void sortDeque();
		void sortVector();

	private:
		std::deque<unsigned int>	_dq;
		std::vector<unsigned int>	_vc;
		bool						_odd;
		
};