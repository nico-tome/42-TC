/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:26:50 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 13:16:31 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("NaN")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
   	std::cout << GREEN << "🆙 ScavTrap default constructor called !" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
   	std::cout << GREEN << "🆙 ScavTrap default constructor called !" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << YELLOW << "🗑️ ScavTrap destructor called !" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    std::cout << GREEN << "🆙 ScavTrap copy constructor called !" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    return (*this);
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        this->energyPoints--;
        std::cout << CYAN << "💥 ScavTrap " << this->name << " attacks " << target
                  << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
    } else {
        std::cout << RED << "🪫 ScavTrap " << this->name << " has no energy or hit points left to attack!" << RESET << std::endl;
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << BLUE << "🛡️ ScavTrap " << this->name << " is now in Gate Keeper mode!" << RESET << std::endl;
}