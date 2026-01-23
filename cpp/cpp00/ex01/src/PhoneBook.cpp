/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:34:54 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 09:32:30 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	this->size = 0;
}

Phonebook::~Phonebook(void) {}

bool is_number(std::string s)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	}
	return (1);
}

void	Phonebook::show_contact(int idx)
{
	std::cout << "First name: " << this->contacts[idx].get_first_name(0) << std::endl;
	std::cout << "Last name: " << this->contacts[idx].get_last_name(0) << std::endl;
	std::cout << "Nickname: " << this->contacts[idx].get_nickname(0) << std::endl;
	std::cout << "Phone Number: " << this->contacts[idx].get_phone_number(0) << std::endl;
	std::cout << "Secret: " << this->contacts[idx].get_secret(0) << std::endl;
}

void	Phonebook::add_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;

	while (1)
	{
		if (std::cin.eof())
			return ;
		std::cout << "Enter your contact first name: ";
		std::getline(std::cin, first_name);
		if (!first_name[0])
			std::cout << "First name cannot be empty." << std::endl;
		else
			break;
	}
	while (1)
	{
		if (std::cin.eof())
			return ;
		std::cout << std::endl << "Enter your contact last name: ";
		std::getline(std::cin, last_name);
		if (!last_name[0])
			std::cout << "Last name cannot be empty." << std::endl;
		else
			break;
	}
	while (1)
	{
		if (std::cin.eof())
			return ;
		std::cout << std::endl << "Enter your contact nickname: ";
		std::getline(std::cin, nickname);
		if (!last_name[0])
			std::cout << "Nickname cannot be empty." << std::endl;
		else
			break;
	}
	while (1)
	{
		if (std::cin.eof())
			return ;
		std::cout << std::endl << "Enter your contact phone number: ";
		std::getline(std::cin, phonenumber);
		if (!last_name[0])
			std::cout << "Phone number cannot be empty." << std::endl;
		else
			break;
	}
	while (1)
	{
		if (std::cin.eof())
			return ;
		std::cout << std::endl << "Enter your contact darkest secret: ";
		std::getline(std::cin, secret);
		if (!last_name[0])
			std::cout << "Secret cannot be empty." << std::endl;
		else
			break;
	}
	std::cout << std::endl;

	this->contacts[this->size % 8].set_new(first_name, last_name, nickname, phonenumber, secret);
	this->size++;

	if (std::cin.eof())
		return ;

	if (this->size >= 8)
		std::cout << "New contact saved ! (oldest one was deleted)" << std::endl;
	else
		std::cout << "New contact saved !" << std::endl;
}

void	Phonebook::search_contact(void)
{
	int	size;
	std::string	index;

	if (this->size == 0)
	{
		std::cout << "There is no contact in this phonebook." << std::endl;
		return ;
	}
	if (this->size > 8)
		size = 7;
	else
		size = this->size;

	std::cout << "o----------o----------o----------o----------o" << std::endl;
	std::cout << "|  Index   | First Na | Last Na  | Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "|" << "    " << i << "     ";
		std::cout << "|" << std::left << std::setw(10) << this->contacts[i].get_first_name(10);
		std::cout << "|" << std::left << std::setw(10) << this->contacts[i].get_last_name(10);
		std::cout << "|" << std::left << std::setw(10) << this->contacts[i].get_nickname(10);
		std::cout << "|" << std::endl;
	}
	std::cout << "o----------o----------o----------o----------o" << std::endl;
	std::cout << std::endl << "Enter an idex: ";
	std::getline(std::cin, index);

	if (std::cin.eof())
		return ;

	if (!is_number(index))
	{
		std::cout << "Index is not a number." << std::endl;
		return ;
	}
	if (std::atoi(index.c_str()) > size)
	{
		std::cout << "Index is out of range." << std::endl;
		return ;
	}
	show_contact(std::atoi(index.c_str()));
}
