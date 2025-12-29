/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:22:51 by ntome             #+#    #+#             */
/*   Updated: 2025/12/28 14:14:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Color.hpp"

Brain::Brain(void)
{
    std::cout << GREEN << "➕ Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << YELLOW << "📋 Brain copy constructor called" << RESET << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << BLUE << "🟰  Brain copy assignment operator called" << RESET << std::endl;
    if (this == &other)
		return (*this);
    
	for (int i = 0; i < 100; i++)
    	this->ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << RED << "🗑️ Brain destructor called" << RESET <<  std::endl;
}

std::string Brain::getIdea(int idx) const
{
    if (idx < 0 || idx >= 100)
    {
        std::cerr << RED << "❌ Brain::getIdea: Index out of bounds" << RESET << std::endl;
        return ("");
    }
    return (this->ideas[idx]);
}

void Brain::setIdea(int idx, const std::string idea)
{
    if (idx < 0 || idx >= 100)
    {
        std::cerr << RED << "❌ Brain::setIdea: Index out of bounds" << RESET << std::endl;
        return ;
    }
    this->ideas[idx] = idea;
}