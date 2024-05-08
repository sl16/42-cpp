/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:53:42 by vbartos           #+#    #+#             */
/*   Updated: 2024/05/08 22:03:23 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(void)
{
	Harl someGuyHarl;

	someGuyHarl.complain("debug");
	someGuyHarl.complain("info");
	someGuyHarl.complain("warning");
	someGuyHarl.complain("error");

	return (0);
}