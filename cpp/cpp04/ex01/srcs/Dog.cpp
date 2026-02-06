/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:19:38 by ntome             #+#    #+#             */
/*   Updated: 2026/02/06 20:44:18 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Color.hpp"

Dog::Dog(void): Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    if (!this->brain)
    {
        std::cerr << RED << "❌ [🐕 Dog] Failed to allocate Brain" << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << GREEN << "➕ [🐕 Dog] Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << YELLOW << "📋 [🐕 Dog] Copy constructor called" << RESET << std::endl;
	this->type = other.type;
    this->brain = new Brain(*(other.brain));
}

Dog::~Dog(void)
{
    delete this->brain;
    std::cout << RED << "🗑️ [🐕 Dog] Destructor called" << RESET <<  std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << CYAN << "🟰 [🐕 Dog] Copy assignment operator called" << RESET << std::endl;
    if (this == &other)
		return (*this);
	delete this->brain;
	this->type = other.type;
    this->brain = new Brain(*(other.brain));

    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << BLUE << "🔉 [🐕 Dog] Woof Woof!" << RESET << std::endl;
}

void Dog::setIdea(int idx, const std::string idea)
{
    this->brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
    return this->brain->getIdea(idx);
}
