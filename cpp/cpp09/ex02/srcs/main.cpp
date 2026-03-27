/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/27 15:11:04 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "color.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>

bool	vec_has(std::vector<int> vec, int element)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it == element)
			return (true);
	}
	return (false);
}

std::vector<int>	parse_input(int ac, char **av)
{
	std::vector<int>	parsed_input;
	for (int i = 1; i < ac; i++) {
		std::string	string_value = av[i];
		int			int_value;
		for (int j = 0; j < (int)string_value.length(); j++) {
			if (!std::isdigit(string_value[j]) && string_value[j] != '+') {
				if (string_value[j] == '.')
					throw std::runtime_error(string_value + " is a floating value, we only accept int value.");
				else if (string_value[j] == '-')
					throw std::runtime_error(string_value + " is a negative value, please enter only values between 0 and 2147483647.");
				else
					throw std::runtime_error(string_value + " is not a numeric value.");
			}
		}
		if (string_value.length() >= 10 && string_value.compare("2147483647") > 0)
			throw std::runtime_error(string_value + " is greater that the int max, please give only values between 0 and 2147483647.");
		int_value = std::atoi(av[i]);
		if (vec_has(parsed_input, int_value))
			throw std::runtime_error(string_value + " is twice in the inpute, I don't let you do that sry 😝 😝 😝 😝");
		parsed_input.push_back(int_value);
	}
	return (parsed_input);
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << RED << "Error: bad input. ./PmergeMe <. . . .>" << RESET << std::endl; 
		return (1);
	}
	std::vector<int>	parsed_val;
	try {
		parsed_val = parse_input(ac, av);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << std::endl;
		return (1);
	}

	PmergeMe<std::vector<int> >	vectorContainer;
	PmergeMe<std::deque<int> >	dequeContainer;
	clock_t						time;

	vectorContainer.addRange(parsed_val.begin(), parsed_val.end());
	dequeContainer.addRange(parsed_val.begin(), parsed_val.end());

	std::cout << YELLOW << "Before: " << RESET;
	vectorContainer.printValues();
	std::cout << std::endl;

	time = clock();
	vectorContainer.sort(1);
	time = clock() - time;

	std::cout << std::endl << GREEN << "After: " << RESET;
	vectorContainer.printValues();
	std::cout << std::endl;

	std::cout << CYAN << "Time to process a range of " << vectorContainer.size() << " elements with std::vector<int> in: " << RESET << ((float)time)/CLOCKS_PER_SEC * 1000 << CYAN << " ms." << RESET << std::endl;

	time = clock();
	dequeContainer.sort(1);
	time = clock() - time;

	std::cout << CYAN << "Time to process a range of " << dequeContainer.size() << " elements with std::deque<int> in: " << RESET << ((float)time)/CLOCKS_PER_SEC * 1000 << CYAN << " ms." << RESET << std::endl;
}
