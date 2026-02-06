/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:18:05 by ntome             #+#    #+#             */
/*   Updated: 2026/02/06 20:45:37 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Color.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cerr << RED << "❌ [🐈 Cat] Failed to allocate brain" << RESET << std::endl;
		exit(1);
	}
    std::cout << GREEN << "➕ [🐈 Cat] Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << YELLOW << "📋 [🐈 Cat] Copy constructor called" << RESET << std::endl;
    this->type = other.type;
    this->brain = new Brain(*(other.brain));
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << RED << "🗑️ [🐈 Cat] Destructor called" << RESET <<  std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << CYAN << "🟰 [🐈 Cat] Copy assignment operator called" << RESET << std::endl;
    if (this == &other)
		return (*this);
	delete this->brain;
    this->type = other.type;
    this->brain = new Brain(*(other.brain));
	return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << BLUE << "🔉 [🐈 Cat] Meow Meow!" << RESET << std::endl;
}

void Cat::setIdea(int idx, const std::string idea)
{
    this->brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
    return this->brain->getIdea(idx);
}
