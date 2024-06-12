/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:11:45 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 10:57:20 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Unspecified Shrubbery Form", 137, 145), _target("N/A")
{
	// std::cout << "[ShrubberyForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Form", 137, 145), _target(target)
{
	// std::cout << "[ShrubberyForm CONSTRUCTOR - " << getName() << "]" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "[ShrubberyForm DESTRUCTOR - " << getName() << "]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.getName(), other.getGradeExec(), other.getGradeSign())
{
	_target = other._target;
	// std::cout << "[ShrubberyForm COPY CONSTRUCTOR - " << getName() << "]" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	//nothing to do here because of const variables
	_target = other._target;
	return (*this);
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (isSigned() == false)
		throw (AForm::ExecutionNotSignedException());
	if (executor.getGrade() > getGradeExec())
		throw (AForm::ExecutionLowGradeException());

	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "              .==@#              " << std::endl;
		file << "        @.#..@=====@@=*-  .      " << std::endl;
		file << "      @===============+.        " << std::endl;
		file << "      .@======+====*%@.         " << std::endl;
		file << " .@====@ @.+=++++@@*#@**#*#@     " << std::endl;
		file << "@=++++++==+++@==*+++******#@@.   " << std::endl;
		file << ".++++++++++%%@*@##*****#****#.   " << std::endl;
		file << "#@@+%+*++@%%@%%+%%*%@@*###@.##=." << std::endl;
		file << "     @..*%++@#%++%***%%*%#*****#@" << std::endl;
		file << "  .*####*%******#**####%%#*****# " << std::endl;
		file << "  .#@######*#*#@****@@###**#=.   " << std::endl;
		file << "     @@#..##*%  ** .:#****@..    " << std::endl;
		file << "                **.              " << std::endl;
		file << "                **               " << std::endl;
		file << "               .**@              " << std::endl;	
	}
	else
		std::cerr << "Unable to open file" << std::endl;
}