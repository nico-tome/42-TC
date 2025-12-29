/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:43:17 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 17:49:32 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << GREEN << "➕ [❤️‍🩹 Cure] Default constructor called" << RESET << std::endl;
}

Cure::~Cure(void)
{
	std::cout << RED << "🗑️ [❤️‍🩹 Cure] Destructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &other): AMateria(other)
{
	std::cout << GREEN << "📋 [❤️‍🩹 Cure] Copy constructor called" << RESET << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << YELLOW << "🟰 [❤️‍🩹 Cure] Assignment operator called" << RESET << std::endl;
	return (*this);
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << BLUE << "❤️‍🩹 * heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}

std::string const	&Cure::getType() const
{
	return (this->_type);
}