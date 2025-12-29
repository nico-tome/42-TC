/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:12:43 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:24:57 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Color.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << GREEN << "➕ [Animal] Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << YELLOW << "📋 [Animal] Copy constructor called" << RESET << std::endl;
    *this = other;
}

Animal::~Animal(void)
{
    std::cout << RED << "🗑️ [Animal] Destructor called" << RESET <<  std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << CYAN << "🟰 [Animal] Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << BLUE << "🔉 [Animal] * generic animal sound *" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}