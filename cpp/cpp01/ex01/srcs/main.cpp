/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:34:47 by ntome             #+#    #+#             */
/*   Updated: 2025/12/23 14:11:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHord(int N, std::string name);

static void	printSeparator(const std::string &title, const std::string &color)
{
	std::cout << std::endl;
	std::cout << color << "========================================" << RESET << std::endl;
	std::cout << color << "  " << title << RESET << std::endl;
	std::cout << color << "========================================" << RESET << std::endl;
}

int main(int ac, char **av)
{
	int			num;
	std::string	name;

	if (ac != 3)
	{
		std::cout << "Need ./Moar_brainz <number of zombies> <name>" << std::endl;
		return (1);
	}
	num = std::atoi(av[1]);
	name = av[2];

	printSeparator("WELCOME TO THE ZOMBIE TEST", MAGENTA);
	printSeparator("CREATE THE HORDE", GREEN);

	Zombie*	horde = zombieHord(num, name);
	if (!horde)
		return (1);

	printSeparator("ANNOUNCE THE ZOMBIES", CYAN);

	for (int zombie = 0; zombie < num; zombie++)
		horde[zombie].announce();

	printSeparator("DELET THE HORDE", RED);

	delete	[]horde;
	return (0);
}

