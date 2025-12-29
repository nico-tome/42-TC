/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:18:11 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 12:45:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << GREEN << "➕ AMateria of type " << this->_type << " created." << RESET << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << RED << "🗑️ AMateria destructor of type " << this->_type << " has been called !" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
	std::cout << GREEN << "📋 AMateria copy of type " << this->_type << " created." << RESET << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << YELLOW << "🟰 AMateria assignment operator called for type " << this->_type << RESET << std::endl;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << BLUE << "* uses " << this->_type << " on " << target.getName() << " *" << RESET << std::endl;
}