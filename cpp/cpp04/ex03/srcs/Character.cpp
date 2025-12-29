/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:46:01 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 18:08:57 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void) {}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << GREEN << "➕  [👤 Character] " << _name << " created!" << RESET << std::endl;
	
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	std::cout << RED << "🗑️  [👤 Character] " << _name << " destroyed!" << RESET <<  std::endl;
	
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

Character::Character(const Character &other)
{
	std::cout << GREEN << "📋  [👤 Character] copy of " << other._name << " created!" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << YELLOW << "🟰  [👤 Character] assignment operator called for " << this->_name << RESET << std::endl;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << MAGENTA << "🎒 " << this->_name << " equipped " << m->getType() << " in slot " << i << RESET << std::endl;
			return ;
		}
	}
	std::cout << YELLOW << "⚠️  👤 " << this->_name << "'s inventory is full! Cannot equip " << m->getType() << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >=4) {
		std::cout << YELLOW << "⚠️  👤 " << this->_name << " cannot unequip from slot " << idx << " (out of bounds)!" << RESET << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL) {
		std::cout << MAGENTA << "🎒 " << this->_name << " unequipped " << this->_inventory[idx]->getType() << " from slot " << idx << RESET << std::endl;
		this->_inventory[idx] = NULL;
	} else {
		std::cout << YELLOW << "⚠️  👤 " << this->_name << "'s slot " << idx << " is already empty!" << RESET << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >=4) {
		std::cout << YELLOW << "⚠️  👤 " << this->_name << " cannot use materia from slot " << idx << " (out of bounds)!" << RESET << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	} else {
		std::cout << YELLOW << "⚠️  👤 " << this->_name << "'s slot " << idx << " is empty! Cannot use materia." << RESET << std::endl;
	}
}