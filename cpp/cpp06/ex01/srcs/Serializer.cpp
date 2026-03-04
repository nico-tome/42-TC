/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:40:45 by ntome             #+#    #+#             */
/*   Updated: 2026/03/03 15:43:21 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>
#include "color.hpp"

Serializer::Serializer(void) {
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::~Serializer(void) {
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &cpy) {
	std::cout << YELLOW << "Serializer copy constructor called" << RESET << std::endl;
	*this = cpy;
}

Serializer &Serializer::operator=(const Serializer &src) {
	if (this == &src)
		return (*this);
	std::cout << BLUE << "Serializer copy assignment operator called" << RESET << std::endl;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}