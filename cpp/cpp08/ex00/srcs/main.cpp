/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/19 13:11:05 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <sstream>

int returnErrorMessage(std::string msg, int error)
{
    std::cout << msg << std::endl;
    return error;
}

int main(int ac, char **av) {
    if (ac <= 2) {
        std::cout << "Usage : /EasyFind *<number_list> <number_to_find>" << std::endl;
        std::cout << "Exemple : /EasyFind 1 2 3 4 2 >> return 0 because number_to_find is 2 and number_list is [1, 2, 3, 4]" << std::endl;
        return (1);
    }

    std::vector<int> numbers;
    int search;
    int current;

    if (!(std::istringstream(av[ac - 1]) >> search))
        return (returnErrorMessage("This entry is not a int !", 1));

    for (int i = 0; i < ac - 2; i++) {
        if (!(std::istringstream(av[i + 1]) >> current))
            return (returnErrorMessage("This entry is not a int !", 1));
        numbers.push_back(current);
    }
    easyfind(numbers, search);
}