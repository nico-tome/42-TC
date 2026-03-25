/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/25 17:32:13 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include "../includes/color.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << std::endl;
	std::cout << GREEN << "Stack Top" << RESET << std::endl;
	std::cout << PURPLE << mstack.top() << RESET << std::endl;
	
	mstack.pop();
	
	std::cout << GREEN << "Stack Size" << RESET << std::endl;
	std::cout << CYAN << mstack.size() << RESET << std::endl;
	std::cout << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}