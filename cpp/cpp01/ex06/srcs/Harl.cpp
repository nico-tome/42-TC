/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:07:52 by ntome             #+#    #+#             */
/*   Updated: 2026/01/29 22:14:47 by ntome            ###   ########.fr       */
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
	int	idx = 0;
	void (Harl::*funcsptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	funcsName[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (idx < 4) {
		if (level == funcsName[idx])
			break;
		idx++;
	}
	switch (idx) {
		case 0:
			(this->*funcsptr[0])();
		case 1:
			(this->*funcsptr[1])();
		case 2:
			(this->*funcsptr[2])();
		case 3:
			(this->*funcsptr[3])();
			break;
		default:
			std::cout << "Level dont correspond to anything." << std::endl;
	}
}
