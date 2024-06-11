/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:15:33 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/11 16:23:02 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int gradeExec, int gradeSign);
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);

		const std::string	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				isSigned() const;
		void				beSigned(Bureaucrat &brc);

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

std::ostream& operator<<(std::ostream& os, const Form& obj);