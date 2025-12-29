/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:18:05 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:19:34 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Color.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    std::cout << GREEN << "➕ [🐈 Cat] Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << YELLOW << "📋 [🐈 Cat] Copy constructor called" << RESET << std::endl;
    *this = other;
}

Cat::~Cat(void)
{
    std::cout << RED << "🗑️ [🐈 Cat] Destructor called" << RESET <<  std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << CYAN << "🟰 [🐈 Cat] Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << BLUE << "🔉 [🐈 Cat] Meow Meow!" << RESET << std::endl;
}