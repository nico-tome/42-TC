/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:49:41 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 17:51:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "➕  [❄️  Ice] Materia created!" << RESET << std::endl;
}

Ice::~Ice(void)
{
	std::cout << RED << "🗑️  [❄️  Ice] Materia destroyed!" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << GREEN << "📋  [❄️  Ice] copy created!" << RESET << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << YELLOW << "🟰  [❄️  Ice] assignment operator called!" << RESET << std::endl;
	return (*this);
}

AMateria* Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << CYAN << "❄️ * shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}

std::string const &Ice::getType(void) const
{
	return (this->_type);
}