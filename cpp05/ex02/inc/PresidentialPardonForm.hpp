/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:53 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/12 11:17:34 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

		const std::string& getTarget() const;

		void	execute(const Bureaucrat& executor) const;

	private:
		std::string _target;
};