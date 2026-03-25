/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/25 18:22:26 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Wrong args number ! ./btc <file.csv>" << RESET << std::endl;
		return 1;
	}
}