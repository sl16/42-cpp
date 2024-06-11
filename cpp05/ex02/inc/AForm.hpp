/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:08:26 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/11 19:27:56 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int gradeExec, int gradeSign);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		const std::string	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				isSigned() const;
		virtual void		beSigned(Bureaucrat &brc) = 0;

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
		const std::string 	_name;
		int					_gradeExec;
		int					_gradeSign;
		bool				_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);