/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:25:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/28 11:14:46 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	_dq = other._dq;
	_ll = other._ll;
}

const PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_dq = other._dq;
		_ll = other._ll;
	}

	return (*this);
}

void PmergeMe::parseInput(char **argv)
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		std::istringstream iss(argv[i]);
		long long num;
		iss >> num;

		if (iss.fail() || iss.peek() != EOF || num < 0)
			throw std::invalid_argument("Error: wrong input (unsigned integers only");

		if (num > std::numeric_limits<unsigned int>::max())
			throw std::invalid_argument("Error: wrong input (integers must be less than MAXUINT");
		
		num = static_cast<unsigned int>(num);

		_dq.push_back(num);
		_ll.push_back(num);
	}
}

void PmergeMe::printBefore()
{
	std::cout << "Deque before : ";
	for (std::deque<unsigned int>::iterator it = _dq.begin(); it != _dq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "List before : ";
	for (std::list<unsigned int>::iterator it = _ll.begin(); it != _ll.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::sortDeque()
{
	// Step 1: Split the container into pairs
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	for (size_t i = 0; i < _dq.size(); i += 2)
	{
		if (i + 1 < _dq.size())
			pairs.push_back(std::make_pair(_dq[i], _dq[i + 1]));
		else
			pairs.push_back(std::make_pair(_dq[i], std::numeric_limits<unsigned int>::max()));
	}

	// Step 2: Compare each pair and find the larger elements, store these in a sorted vector (::sort uses IntroSort)
	std::vector<unsigned int> larger;
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
		larger.push_back(it->second);
	}
	std::sort(larger.begin(), larger.end());

	// Step 3: Insert the smaller element of the first pair at the start of the sorted list, insert all larger pair members
	std::deque<unsigned int> sorted;
	sorted.push_front(pairs[0].first);
	sorted.insert(sorted.end(), larger.begin(), larger.end());

	// Step 4: Insert the remaining elements into the sorted list
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin() + 1; it != pairs.end(); ++it)
	{
		std::deque<unsigned int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), it->first);
		sorted.insert(pos, it->first);
	}

	_dq = sorted;
}


// Split the list into pairs. Create a new list where each element is a pair of elements from the original list. If the original list has an odd number of elements, the last pair should contain the last element and a sentinel value that is greater than any possible value in the list.

// Sort each pair and find the larger elements. For each pair, if the first element is greater than the second, swap them. Then, add the second element (which is now the larger one) to a new list of larger elements.

// Recursively sort the larger elements. Use a recursive function to sort the list of larger elements. This will be the first part of the sorted list.

// Insert the smaller element of the first pair at the start of the sorted list. The smaller element of the first pair is the element that was paired with the first and smallest element of the sorted list.

// Insert the remaining elements into the sorted list. The remaining elements are the smaller elements of the pairs, excluding the first one. Insert them into the sorted list one at a time, using binary search to find the correct position for each element. The insertion order is determined by a specially chosen sequence.