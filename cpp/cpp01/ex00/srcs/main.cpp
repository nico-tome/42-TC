/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:34:47 by ntome             #+#    #+#             */
/*   Updated: 2025/12/23 13:40:45 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

static void	printSeparator(const std::string &title, const std::string &color)
{
	std::cout << std::endl;
	std::cout << color << "========================================" << RESET << std::endl;
	std::cout << color << "  " << title << RESET << std::endl;
	std::cout << color << "========================================" << RESET << std::endl;
}

int main(void)
{
	printSeparator("WELCOME TO THE ZOMBIE TEST", MAGENTA);

	// Heap zombies
	printSeparator("HEAP ZOMBIES", CYAN);

	Zombie* z1 = newZombie("Walker");
	Zombie* z2 = newZombie("Crawler");
	Zombie* z3 = newZombie("Runner");

	z1->announce();
	z2->announce();
	z3->announce();

	printSeparator("DESTROYING HEAP ZOMBIES", RED);

	delete z1;
	delete z2;
	delete z3;

	// Stack zombies
	printSeparator("STACK ZOMBIES", GREEN);

	randomChump("Biter");
	randomChump("Ghoul");
	randomChump("Stalker");

	printSeparator("END OF THE APOCALYPSE", YELLOW);

	return (0);
}

