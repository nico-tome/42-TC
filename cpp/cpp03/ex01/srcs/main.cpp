/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/26 00:49:18 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Donald");
	ClapTrap trapclap("Vlad");
    ScavTrap scavTrap("Gogol");
    scavTrap.attack("Saucisse");
    scavTrap.guardGate();
    scavTrap.attack("Saucisse");
    scavTrap.takeDamage(20);
    scavTrap.beRepaired(10);
    scavTrap.takeDamage(90);
    scavTrap.beRepaired(5);
    scavTrap.attack("Saucisse");

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
