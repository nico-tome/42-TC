/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:31:46 by ntome             #+#    #+#             */
/*   Updated: 2026/03/07 18:44:10 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int size, void (*f)(T &))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void print_element(T &e)
{
	std::cout << e << std::endl;
}

#endif