/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/26 18:04:22 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "color.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << RED << "Error: Bad input." << RESET << std::endl;
		return (1);
	}
	RPN	rpn;
	rpn.calculate(av[1]);
}
