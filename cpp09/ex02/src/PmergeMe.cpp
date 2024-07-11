/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:25:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/07/11 15:38:49 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
// https://en.wikipedia.org/wiki/Merge-insertion_sort


#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_odd = false;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	_dq = other._dq;
	_ll = other._ll;
	_odd = false;
}

const PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_dq = other._dq;
		_ll = other._ll;
		_odd = false;
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
			throw std::invalid_argument("Error: wrong input (unsigned integers only)");

		if (num > std::numeric_limits<unsigned int>::max())
			throw std::invalid_argument("Error: wrong input (integers must be less than MAXUINT)");
		
		num = static_cast<unsigned int>(num);

		_dq.push_back(num);
		_ll.push_back(num);
	}
}

void PmergeMe::printOrder(std::string when)
{
	if (when == "before")
		std::cout << "Before:\t";
	else
		std::cout << "After:\t";
	for (std::deque<unsigned int>::iterator it = _dq.begin(); it != _dq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printTime(std::clock_t& start, std::clock_t& end)
{
	double duration;
	
	duration = (end - start) * 1000000.0 / static_cast<double>(CLOCKS_PER_SEC);
	std::cout << "Time taken : " << duration << " us\n";}

static void quickSort(std::vector<unsigned int>& arr, int left, int right)
{
	int i = left, j = right;
	unsigned int pivot = arr[(left + right) / 2];

	// Partition
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	// Recursion
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
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
		{
			pairs.push_back(std::make_pair(_dq[i], std::numeric_limits<unsigned int>::max()));
			_odd = true;
		}
	}

	// Step 2: Compare each pair and find the larger elements, store these in a sorted vector
	std::vector<unsigned int> larger;
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
		larger.push_back(it->second);
	}
	quickSort(larger, 0, larger.size() - 1);

	// Step 3: Insert at the start of [sorted] the element that was paired with the first and smallest element of [larger]
	std::deque<unsigned int> sorted;

	unsigned int min_larger = larger[0];
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (std::max(it->first, it->second) == min_larger)
			break;
	}
	if (it != pairs.end())
		sorted.push_front(std::min(it->first, it->second));

	// Step 4: Insert all elements from 'larger' into 'sorted'
	sorted.insert(sorted.end(), larger.begin(), larger.end());

	// Step 5: Insert the remaining elements into the sorted list
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin() + 1; it != pairs.end(); ++it)
	{
		std::deque<unsigned int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), it->first);
		sorted.insert(pos, it->first);
	}
	if (_odd == true)
		sorted.erase(sorted.end() - 1);

	_dq = sorted;
}
