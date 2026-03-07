/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/07 18:50:45 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "color.hpp"
#include <iostream>

int main()
{
    int ints[] = { 0, 1, 2, 3, 4 };
    int sizeInts = sizeof(ints) / sizeof(ints[0]);

    std::cout << GREEN << "\n--- testing with int array ---" << RESET << std::endl;
    iter(ints, sizeInts, &print_element);
    iter(ints, sizeInts, &print_element);
    iter(ints, sizeInts, &print_element);

    const int constInts[] = { 10, 20, 30 };
    int sizeConstInts = sizeof(constInts) / sizeof(constInts[0]);

    std::cout << GREEN << "\n--- testing with const int array ---" << RESET << std::endl;
    iter(constInts, sizeConstInts, &print_element);

    const std::string words[] = { "hello", "world", "iter" };
    int sizeWords = sizeof(words) / sizeof(words[0]);

    std::cout << GREEN << "\n--- testing with const std::string array ---" << RESET << std::endl;
    iter(words, sizeWords, print_element);

    float floats[] = { 0.5f, 1.5f, 2.5f };
    int sizeFloats = sizeof(floats) / sizeof(floats[0]);

    std::cout << GREEN << "\n--- testing with float array ---" << RESET << std::endl;
    iter(floats, sizeFloats, print_element);

    return 0;
}