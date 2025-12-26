/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: FragTrap::attackDamage25/12/26 00:26:50 by ntome             #+#    #+#             */
/*   Updated: 2025/12/26 01:27:04 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("NaN")
{
    ClapTrap::name = "NaN_clap_name";
    this->name = "NaN";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
   	std::cout << GREEN << "🆙 DiamondTrap default constructor called !" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
   	std::cout << GREEN << "🆙 DiamondTrap default constructor called !" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << YELLOW << "🗑️ DiamondTrap destructor called on " << this->name << " !" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    std::cout << GREEN << "🆙 DiamondTrap copy constructor called !" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    return (*this);
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void)
{
	std::cout << CYAN << "🤖 DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << RESET << std::endl;
}