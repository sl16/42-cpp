/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:50:42 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/05 16:57:16 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		
		const std::string&	getName() const;
		int					getGrade() const;

		void				raiseGrade();
		void				lowerGrade();

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		int					_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);