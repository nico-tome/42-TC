/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:01:14 by ntome             #+#    #+#             */
/*   Updated: 2025/12/26 01:09:24 by ntome            ###   ########.fr       */
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

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	this->name = assign.name;
	this->hitPoints = assign.hitPoints;
	this->energyPoints = assign.energyPoints;
	this->attackDamage = assign.attackDamage;

	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->energyPoints--;
		std::cout << RED << "💥 ClapTrap " << this->name << "attacks " << target 
			<< ", causing " << this->attackDamage << " points of damage !" << RESET << std::endl;
	}
	else if (this->hitPoints <= 0) {
		std::cout << RED << "🚫 ClapTrap " << this->name << " try to attack " << target
		<< " but don't have enought hit point." << RESET << std::endl;
	}
	else if (this->energyPoints <= 0) {
		std::cout << RED << "🚫 ClapTrap " << this->name << "try to attack " << target 
		<< " but dont't have enought energy point." << RESET << std::endl;
	}

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << MAGENTA << "🤕 ClapTrap " << this->name << " take " << amount << " damages and now have "
	<< this->hitPoints << " hit point(s) !" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << CYAN << "🔋 ClapTrap " << this->name << " repaired " << amount << " hit point(s) and now have: "
		<< "hitPoints: " << this->hitPoints << " energyPoints: " << this->energyPoints << RESET << std::endl;
	}
	else if (this->hitPoints <= 0) {
		std::cout << CYAN << "🚫 ClapTrap " << this->name << " try to be repaired by " << amount << " hit point(s)"
		<< " but don't have enought hit point." << RESET << std::endl;
	}
	else if (this->energyPoints <= 0) {
		std::cout << CYAN << "🚫 ClapTrap " << this->name << "try to be repaired by " << amount << " hit point(s)"
		<< " but dont't have enought energy point." << RESET << std::endl;
	}
}
