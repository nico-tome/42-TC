/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:01:14 by ntome             #+#    #+#             */
/*   Updated: 2026/01/30 10:03:58 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    this->name = "Default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << GREEN << "🆙 ClapTrap default constructor called !" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << GREEN << "🆙 ClapTrap constructor called !" << RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << YELLOW << "🗑️ ClapTrap destructor called !" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    std::cout << GREEN << "🆙 ClapTrap copy constructor called !" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << RED << "💥 ClapTrap " << this->name << " attacks " << target
                  << ", causing " << this->attackDamage << " points of damage !" << RESET << std::endl;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << RED << "🚫 ClapTrap " << this->name << " tried to attack " << target
                  << " but doesn't have enough hit points." << RESET << std::endl;
    }
    else if (this->energyPoints <= 0)
    {
        std::cout << RED << "🚫 ClapTrap " << this->name << " tried to attack " << target
                  << " but doesn't have enough energy points." << RESET << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
    std::cout << MAGENTA << "🤕 ClapTrap " << this->name << " took " << amount << " damage and now has "
              << this->hitPoints << " hit point(s) !" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << CYAN << "🔋 ClapTrap " << this->name << " repaired " << amount << " hit point(s) and now has: "
                  << "HitPoints: " << this->hitPoints << " EnergyPoints: " << this->energyPoints << RESET << std::endl;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << CYAN << "🚫 ClapTrap " << this->name << " tried to be repaired by " << amount << " hit point(s)"
                  << " but doesn't have enough hit points." << RESET << std::endl;
    }
    else if (this->energyPoints <= 0)
    {
        std::cout << CYAN << "🚫 ClapTrap " << this->name << " tried to be repaired by " << amount << " hit point(s)"
                  << " but doesn't have enough energy points." << RESET << std::endl;
    }
}
