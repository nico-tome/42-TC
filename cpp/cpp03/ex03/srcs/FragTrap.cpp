/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:26:50 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 13:15:48 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("NaN")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
   	std::cout << GREEN << "🆙 FragTrap default constructor called !" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
   	std::cout << GREEN << "🆙 FragTrap default constructor called !" << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << YELLOW << "🗑️ FragTrap destructor called !" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    std::cout << GREEN << "🆙 FragTrap copy constructor called !" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;

    return (*this);
}

void    FragTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        this->energyPoints--;
        std::cout << CYAN << "💥 FragTrap " << this->name << " attacks " << target
                  << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
    } else {
        std::cout << RED << "🪫 FragTrap " << this->name << " has no energy or hit points left to attack!" << RESET << std::endl;
    }
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << MAGENTA << "✋ FragTrap " << this->name << " is requesting a high five! ✋" << RESET << std::endl;
}