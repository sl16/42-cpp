/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 13:27:12 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/utils.hpp"

int main(void)
{
	srand(time(0));
	
	Base *class1;
	Base *class2;
	Base *class3;

	class1 = generate();
	class2 = generate();
	class3 = generate();

	std::cout << "POINTERS:" << std::endl;

	identify(class1);
	identify(class2);
	identify(class3);

	std::cout << "---------" << std::endl;

	Base& class4 = *class1;
	Base& class5 = *class2;
	Base& class6 = *class3;

	std::cout << "REFERENCES:" << std::endl;

	identify(class4);
	identify(class5);
	identify(class6);

	std::cout << "---------" << std::endl;

	delete (class1);
	delete (class2);
	delete (class3);
}