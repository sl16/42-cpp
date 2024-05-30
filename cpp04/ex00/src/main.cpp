/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:12:41 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/30 13:35:24 by vbartos          ###   ########.fr       */
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
	std::cout << MAGENTA << "CORRECT" << RESET << std::endl << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " ";
	j->makeSound();
	
	std::cout << i->getType() << " ";
	i->makeSound();

	std::cout << meta->getType() << " ";
	meta->makeSound();

	std::cout << std::endl;
	std::cout << MAGENTA << "INCORRECT" << RESET << std::endl << std::endl;

	const WrongCat *k = new WrongCat();
	const WrongAnimal *l = new WrongAnimal();
	
	std::cout << k->getType() << " ";
	k->makeSound();

	std::cout << l->getType() << " ";
	l->makeSound();

	std::cout << std::endl;
	std::cout << MAGENTA << "DESTRUCTION" << RESET << std::endl << std::endl;

	delete i;
	delete j;
	delete k;
	delete l;
	delete meta;

	return (0);
}