/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/25 19:43:46 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Donald");
	ClapTrap trapclap("Vlad");

    clapTrap.attack("Saucisse");
	clapTrap.attack("Saucisse");
	trapclap.attack("Donald");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(10);
    clapTrap.takeDamage(30);
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(30);
	trapclap.takeDamage(30);
	trapclap.beRepaired(10);
    return 0;
}
