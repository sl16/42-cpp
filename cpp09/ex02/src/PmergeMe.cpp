/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:25:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/07/27 14:30:31 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RESOURCES
// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://medium.com/@sofia.huppertz/cpp09-school42-1efa42df7803
// https://www.linkedin.com/posts/nerraou_ford-johnson-merge-insertion-sort-activity-7076577075712675840-AJ1l
// https://github.com/andreaulicna/42_CPP_modules/tree/main/CPP_Module_09/ex02 (thx for saving my ass)


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
	_vc = other._vc;
	_odd = false;
}

const PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_dq = other._dq;
		_vc = other._vc;
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
		_vc.push_back(num);
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

void PmergeMe::printTime(std::clock_t& start, std::clock_t& end, std::string type, int argc)
{
	double duration;
	
	duration = (end - start) * 1000000.0 / static_cast<double>(CLOCKS_PER_SEC);
	std::cout << "Time taken for " << type << " with " << argc - 1 << " elements: " << duration << " us\n";}

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

static unsigned int	calcJacobsthalNumber(unsigned int i)
{
	if (i == 0 || i == 1)
		return (i);
	return (calcJacobsthalNumber(i - 1) + 2 * calcJacobsthalNumber(i - 2));

}

static std::vector<unsigned int> generateJacobsthalNumbers(size_t count)
{
    std::vector<unsigned int> jacobsthalNumbers;
    unsigned int	i;

	i = 3;
	while (count > calcJacobsthalNumber(i))
	{
		jacobsthalNumbers.push_back(calcJacobsthalNumber(i));
		i++;
	}
	jacobsthalNumbers.push_back(calcJacobsthalNumber(i));

    return jacobsthalNumbers;
}

static std::vector<unsigned int> generateInsertionSequence(std::vector<unsigned int>& jacobsthalSequence)
{
	std::vector<unsigned int> insertionSequence;
	unsigned int currentValue;
	unsigned int previousValue = 1;

	for(std::vector<unsigned int>::iterator it = jacobsthalSequence.begin(); it != jacobsthalSequence.end(); ++it)
	{
		currentValue = *it;
		insertionSequence.push_back(currentValue);
		for (size_t j = 1; currentValue - j > previousValue; j++)
			insertionSequence.push_back(currentValue - j);
		previousValue = currentValue;
	}
	return (insertionSequence);
}

void PmergeMe::sortDeque()
{
	// Step 1: Split the container into pairs
	unsigned int oddNum;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	for (size_t i = 0; i < _dq.size(); i += 2)
	{
		if (i + 1 < _dq.size())
			pairs.push_back(std::make_pair(_dq[i], _dq[i + 1]));
		else
		{
			// pairs.push_back(std::make_pair(_dq[i], std::numeric_limits<unsigned int>::max()));
			oddNum = _dq[i];
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

	// // DEBUG
	// std::cout << "LARGER: ";
	// for(std::vector<unsigned int>::iterator printIt = larger.begin(); printIt != larger.end(); printIt++)
	// 	std::cout << *printIt << " ";
	// std::cout << std::endl;
	// // END DEBUG

	// Step 3: Insert at the start of [sorted] the element that was paired with the first and smallest element of [larger]
	std::deque<unsigned int> sorted;

	unsigned int min_larger = larger[0];
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (std::max(it->first, it->second) == min_larger)
			break;
	}
	unsigned int manually_inserted = std::min(it->first, it->second);
	if (it != pairs.end())
		sorted.push_front(manually_inserted);

	// Step 4: Insert all elements from 'larger' into 'sorted'
	sorted.insert(sorted.end(), larger.begin(), larger.end());

	// Step 5: Generate Jacobsthal sequence
	std::vector<unsigned int> jacobsthalSeq = generateJacobsthalNumbers(pairs.size());
	std::vector<unsigned int>::iterator jacobIt;

	// // DEBUG
	// std::cout << "JACOBSTHAL SEQUENCE: ";
	// for (std::vector<unsigned int>::iterator seqIt = jacobsthalSeq.begin(); seqIt != jacobsthalSeq.end(); ++seqIt)
	// 	std::cout << *seqIt << " ";
	// std::cout << std::endl;
	// // END DEBUG

	// Step 6: Generate insert sequence, decrease the values by one for correct index access
	std::vector<unsigned int> insertionSeq = generateInsertionSequence(jacobsthalSeq);

	// // DEBUG
	// std::cout << "INSERTION SEQUENCE: ";
	// for (std::vector<unsigned int>::iterator seqIt = insertionSeq.begin(); seqIt != insertionSeq.end(); ++seqIt)
	// 	std::cout << *seqIt << " ";
	// std::cout << std::endl;
	// // END DEBUG

	for(size_t i = 0; i < insertionSeq.size(); i++)
		insertionSeq[i] -= 1;

	// // DEBUG
	// std::cout << "SMALLER: ";
	// for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	// 	std::cout << it->first << " ";
	// std::cout << std::endl;
	// // END DEBUG

	// Step 7: Insert the remaining elements into the sorted list using the insertion sequence
	for (size_t i = 0; i < insertionSeq.size(); i++)
	{
		unsigned int index;
		unsigned int num;
		std::deque<unsigned int>::iterator it;
		
		index = insertionSeq[i];
		if (index < pairs.size())
		{
			num = pairs[index].first;
			if (num == manually_inserted)
				continue;
			it = std::upper_bound(sorted.begin(), sorted.end(), num);
			sorted.insert(it, num);
		}
	}
	if (_odd == true)
	{
		std::deque<unsigned int>::iterator it;
		it = std::upper_bound(sorted.begin(), sorted.end(), oddNum);
		// std::cout << "oddNum is: " << oddNum << std::endl;
		sorted.insert(it, oddNum);
	}

	_dq = sorted;
}

void PmergeMe::sortVector()
{
	// Step 1: Split the container into pairs
	unsigned int oddNum;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	for (size_t i = 0; i < _vc.size(); i += 2)
	{
		if (i + 1 < _vc.size())
			pairs.push_back(std::make_pair(_vc[i], _vc[i + 1]));
		else
		{
			// pairs.push_back(std::make_pair(_vc[i], std::numeric_limits<unsigned int>::max()));
			oddNum = _vc[i];
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
	std::vector<unsigned int> sorted;

	unsigned int min_larger = larger[0];
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (std::max(it->first, it->second) == min_larger)
			break;
	}
	unsigned int manually_inserted = std::min(it->first, it->second);
	if (it != pairs.end())
		sorted.insert(sorted.begin(), manually_inserted);

	// Step 4: Insert all elements from 'larger' into 'sorted'
	sorted.insert(sorted.end(), larger.begin(), larger.end());

	// Step 5: Generate Jacobsthal sequence
	std::vector<unsigned int> jacobsthalSeq = generateJacobsthalNumbers(pairs.size());
	std::vector<unsigned int>::iterator jacobIt;

	// Step 6: Generate insert sequence, decrease the values by one for correct index access
	std::vector<unsigned int> insertionSeq = generateInsertionSequence(jacobsthalSeq);
	std::vector<unsigned int>::iterator seqIt;

	for(size_t i = 0; i < insertionSeq.size(); i++)
		insertionSeq[i] -= 1;

	// Step 7: Insert the remaining elements into the sorted list using the insertion sequence
	for (size_t i = 0; i < insertionSeq.size(); i++)
	{
		unsigned int index;
		unsigned int num;
		std::vector<unsigned int>::iterator it;
		
		index = insertionSeq[i];
		if (index < pairs.size())
		{
			num = pairs[index].first;
			if (num == manually_inserted)
				continue;
			it = std::upper_bound(sorted.begin(), sorted.end(), num);
			sorted.insert(it, num);
		}
	}
	if (_odd == true)
	{
		std::vector<unsigned int>::iterator it;
		it = std::upper_bound(sorted.begin(), sorted.end(), oddNum);
		sorted.insert(it, oddNum);
	}

	_vc = sorted;
}