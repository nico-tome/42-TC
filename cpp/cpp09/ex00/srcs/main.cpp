/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/27 15:24:50 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "color.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Wrong args number ! ./btc <file.csv>" << RESET << std::endl;
		return 1;
	}

	BitcoinExchange	btc;
	
	try
	{
		btc.loadData("data.csv");
	} catch(const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << '\n';
		return 1;
	}
	try
	{
		btc.printExchange(av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << '\n';
	}
	
	
}
