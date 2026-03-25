/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:42:24 by ntome             #+#    #+#             */
/*   Updated: 2026/03/19 13:11:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include "color.hpp"

template <typename T>
void	easyfind(T &container, int element) {
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), element);
	if (it != container.end())
		std::cout << BLUE <<"Element " << RESET << GREEN << element << RESET << BLUE << " found at index: " << RESET << GREEN << it - container.begin() << RESET << std::endl;
	else
		std::cout << RED << "Element " << RESET << GREEN << element << RESET << RED << " not found" << RESET << std::endl; 
}

#endif