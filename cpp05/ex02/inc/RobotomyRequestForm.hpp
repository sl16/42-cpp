/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:53 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 10:57:33 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		const std::string& getTarget() const;

		void	execute(const Bureaucrat& executor) const;

	private:
		std::string _target;
};