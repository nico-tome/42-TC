/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:22:57 by ntome             #+#    #+#             */
/*   Updated: 2026/03/25 17:26:40 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "color.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	std::cout << GREEN << "MutantStack default constructor called !" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
{
	std::cout << YELLOW << "MutantStack copy constructor called !" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << RED << "MutantStack destructor called !" << RESET << std::endl;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &src)
{
	if (this == &src)
		return *this;
	std::stack<T>::operator=(src);
	std::cout << BLUE << "= operator called !" << RESET << std::endl;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return std::stack<T>::c.end();
}