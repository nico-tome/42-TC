/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:31:46 by ntome             #+#    #+#             */
/*   Updated: 2026/03/13 15:05:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, const int size, void (*f)(F &))
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