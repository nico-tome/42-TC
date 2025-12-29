/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:19:38 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:28:09 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Color.hpp"

Dog::Dog(): Animal()
{
    this->type = "Dog";
    std::cout << GREEN << "➕ [🐕 Dog] Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << YELLOW << "📋 [🐕 Dog] Copy constructor called" << RESET << std::endl;
    *this = other;
}

Dog::~Dog(void)
{
    std::cout << RED << "🗑️ [🐕 Dog] Destructor called" << RESET <<  std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << CYAN << "🟰 [🐕 Dog] Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << BLUE << "🔉 [🐕 Dog] Woof Woof!" << RESET << std::endl;
}