/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:25:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/07/11 18:36:17 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://medium.com/@sofia.huppertz/cpp09-school42-1efa42df7803
// https://www.linkedin.com/posts/nerraou_ford-johnson-merge-insertion-sort-activity-7076577075712675840-AJ1l


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

static std::vector<unsigned int> generateJacobsthalNumbers(size_t count)
{
	std::vector<unsigned int> jacobsthalNumbers;
	if (count == 0) return jacobsthalNumbers;

	// Initialize the first two Jacobsthal numbers (starting from 3 since we pushed the first one already)
	unsigned int jacobsthalPrevious = 3; 
	unsigned int jacobsthalCurrent = 5;

	jacobsthalNumbers.push_back(jacobsthalPrevious);
	if (count == 1) return jacobsthalNumbers;

	jacobsthalNumbers.push_back(jacobsthalCurrent);
	if (count == 2) return jacobsthalNumbers;

	// Generate the next Jacobsthal numbers
	for (size_t i = 2; i < count; ++i)
	{
		unsigned int temp = jacobsthalCurrent;
		jacobsthalCurrent = jacobsthalCurrent + 2 * jacobsthalPrevious;
		jacobsthalPrevious = temp;
		jacobsthalNumbers.push_back(jacobsthalCurrent);
	}

	return (jacobsthalNumbers);
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
		std::deque<unsigned int>::iterator it;
		
		index = insertionSeq[i];
		if (index < pairs.size())
		{
			num = pairs[index].second;
			it = std::upper_bound(sorted.begin(), sorted.end(), num);
			sorted.insert(it, num);
		}
	}
	if (_odd == true)
	{
		std::deque<unsigned int>::iterator it;
		it = std::upper_bound(sorted.begin(), sorted.end(), oddNum);
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
	if (it != pairs.end())
		sorted.insert(sorted.begin(), std::min(it->first, it->second));

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
			num = pairs[index].second;
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