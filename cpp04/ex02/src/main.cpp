/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:12:41 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/31 23:27:38 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

int main()
{	
	{
		std::cout << MAGENTA << "DEEP COPPY PROOF" << RESET << std::endl << std::endl;
		
		const Dog *lol1 = new Dog();
		const Dog *lol2 = new Dog(*lol1);
		Dog *lol3 = new Dog();
		*lol3 = *lol1;

		delete lol1;
		delete lol2;
		delete lol3;
	}
	
	std::cout << std::endl << MAGENTA << "FILL ARRAY" << RESET << std::endl << std::endl;

	Animal *animals[100];
	for (int i = 0; i < 50; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Dog();
	}

	for (int i = 50; i < 100; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Cat();
	}

	std::cout << std::endl << MAGENTA << "DELETE ARRAY" << RESET << std::endl << std::endl;

	for (int i = 0; i < 100; ++i)
	{
		std::cout << i << std::endl;
		delete animals[i];
	}

	// const Animal* meta = new Animal();

	return (0);
}