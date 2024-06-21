/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:50:32 by vbartos           #+#    #+#             */
/*   Updated: 2024/06/21 11:01:04 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main(void)
{
	Data 		data;
	Data		*newdata;
	uintptr_t 	raw;

	data.a = 5;
	data.b = 5.5f;
	data.c = 5.55555555;

	raw = Serializer::serialize(&data);
	newdata = Serializer::deserialize(raw);

	std::cout << "old data ptr: " << &data << std::endl;
	std::cout << "new data ptr: " << newdata << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << "old data: a(" << data.a <<"), b(" << data.b << "), c(" << data.c << ")" << std::endl;
	std::cout << "new data: a(" << newdata->a <<"), b(" << newdata->b << "), c(" << newdata->c << ")" << std::endl;
}