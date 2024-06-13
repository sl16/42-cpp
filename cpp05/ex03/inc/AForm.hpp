/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:08:26 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/13 06:49:22 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "./Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(std::string name, int gradeExec, int gradeSign);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		const std::string&	getName() const;
		const int&			getGradeSign() const;
		const int&			getGradeExec() const;
		bool				isSigned() const;
		void				beSigned(Bureaucrat &brc);
		virtual void		execute(const Bureaucrat& executor) const = 0;

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

		class ExecutionNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class ExecutionLowGradeException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	private:
		const std::string 	_name;
		const int			_gradeExec;
		const int			_gradeSign;
		bool				_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);