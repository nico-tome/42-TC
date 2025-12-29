/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:03:01 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 18:07:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << GREEN << "➕  [📚 MateriaSource] created!" << RESET << std::endl;
	
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << RED << "🗑️  [📚 MateriaSource] destroyed!" << RESET <<  std::endl;
	
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << GREEN << "📋  [📚 MateriaSource] copy created!" << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << YELLOW << "🟰  [📚 MateriaSource] assignment operator called!" << RESET << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << GREEN << "➕  [📚 MateriaSource] learned materia of type " << m->getType() << "!" << RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << "❌  [📚 MateriaSource] inventory full, cannot learn more materia!" << RESET << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type) {
			std::cout << GREEN << "➕  [📚 MateriaSource] created materia of type " << type << "!" << RESET << std::endl;
			return (this->_inventory[i]->clone());
		}
	}
	std::cout << RED << "❌  [📚 MateriaSource] materia of type " << type << " not found!" << RESET << std::endl;
	return (NULL);
}