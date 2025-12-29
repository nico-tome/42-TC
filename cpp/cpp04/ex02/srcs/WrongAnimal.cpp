/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:48 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:23:29 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/Color.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << GREEN << "➕ [WrongAnimal] Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << YELLOW << "📋 [WrongAnimal] Copy constructor called" << RESET << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << RED << "🗑️ [WrongAnimal] Destructor called" << RESET <<  std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << CYAN << "🟰 [WrongAnimal] Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << BLUE << "🔉 [WrongAnimal] * generic wrong animal sound *" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}