/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/26 01:34:01 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Donald");
    ClapTrap trapclap("Vlad");
    ScavTrap scavTrap("Gogol");
    FragTrap fragTrap("Mickey");
    FragTrap fragTrap2(fragTrap);
    FragTrap fragTrap3("Caca");
    DiamondTrap diamondTrap("Sparky");
    DiamondTrap diamondTrap2("Diamond2");

    fragTrap.attack("Saucisse");
    fragTrap.highFivesGuys();
    fragTrap2.attack("Saucisse");
    fragTrap2.highFivesGuys();
    fragTrap3.attack("Saucisse");
    fragTrap3.highFivesGuys();
    fragTrap.takeDamage(30);
    fragTrap.beRepaired(20);
    fragTrap.takeDamage(90);
    fragTrap.beRepaired(10);
    fragTrap.attack("Saucisse");
    fragTrap2.attack("Saucisse");
    fragTrap3.attack("Saucisse");
    fragTrap2.takeDamage(200);
    fragTrap2.beRepaired(50);
    fragTrap3.takeDamage(50);
    fragTrap3.beRepaired(25);

    scavTrap.attack("Saucisse");
    scavTrap.guardGate();
    scavTrap.attack("Saucisse");
    scavTrap.takeDamage(20);
    scavTrap.beRepaired(10);
    scavTrap.takeDamage(90);
    scavTrap.beRepaired(5);
    scavTrap.attack("Saucisse");

    diamondTrap.attack("Target");
    diamondTrap.takeDamage(25);
    diamondTrap.beRepaired(15);
    diamondTrap.highFivesGuys();
    diamondTrap.guardGate();
    diamondTrap2.attack("Saucisse");
    diamondTrap2.takeDamage(40);
    diamondTrap2.beRepaired(20);
    diamondTrap2.whoAmI();
    diamondTrap.whoAmI();

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
