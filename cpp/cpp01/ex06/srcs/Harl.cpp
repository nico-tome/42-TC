/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:07:52 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 00:20:59 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "This is a debug message." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "This is a info message." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "This is a warning message." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is a error message." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	print = 0;
	void (Harl::*funcsptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	funcsName[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == funcsName[i] || print == 1) {
			(this->*funcsptr[i])();
			print = 1;
		}
	}
	if (!print)
		std::cout << "Level dont correspond to anything." << std::endl;
}
