/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:41:20 by ntome             #+#    #+#             */
/*   Updated: 2025/12/22 17:58:21 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	std::string	cmd;
	Phonebook	phonebook;

	while (true)
	{
		if (std::cin.eof())
			return (1);
		std::cout << "Type a command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (1);
		if (cmd == "ADD")
			phonebook.add_contact();
		else if (cmd == "SEARCH")
			phonebook.search_contact();
		else if (cmd == "EXIT")
			return (0);
		else
			std::cout << "Command not valid" << std::endl;
	}
}
