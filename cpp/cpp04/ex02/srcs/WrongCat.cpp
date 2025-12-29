/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:23:31 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:24:12 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "../includes/Color.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << GREEN << "➕ [🐈 WrongCat] Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << YELLOW << "📋 [🐈 WrongCat] Copy constructor called" << RESET << std::endl;
    *this = other;
}

WrongCat::~WrongCat(void)
{
    std::cout << RED << "🗑️ [🐈 WrongCat] Destructor called" << RESET <<  std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << CYAN << "🟰 [🐈 WrongCat] Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << BLUE << "🔉 [🐈 WrongCat] Waf... hum, Meow Meow!" << RESET << std::endl;
}