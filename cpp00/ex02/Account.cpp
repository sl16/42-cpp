/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:50:36 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/02 20:43:33 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Account.hpp"

// DEFINE STATIC VARIABLES (DECLARATION IN HEADER IS NOT ENOUGH IN C++)

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// CONSTRUCTOR && DESTRUCTOR

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	this->_accountIndex = getNbAccounts() - 1;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
	return ;
}

// STATIC MEMBER FUNCTIONS

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
	return ;
}

void Account::_displayTimestamp(void)
{
	std::time_t	t;
	std::tm*	now;
	char		buf[20];

	t = std::time(0);
	now = std::localtime(&t);
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", now);
	std::cout << "[";
	std::cout << buf;
	std::cout << "] ";
	return ;
}

// CUSTOM MEMBER FUNCTIONS && HELPER FUNCTIONS

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";deposit:" << deposit;
	
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->checkAmount();
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->checkAmount();
		std::cout << ";withdrawal:" << withdrawal;

		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;

		std::cout << ";amount:" << this->checkAmount();
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}