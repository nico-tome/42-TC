/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:24:33 by ntome             #+#    #+#             */
/*   Updated: 2025/12/22 17:25:09 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string	Contact::get_first_name(int max_size)
{
	int	size = this->first_name.length();
	std::string	substr;

	if (max_size > 0 && size > max_size)
	{
		substr = this->first_name.substr(0, max_size - 1);
		substr.push_back('.');
		return (substr);
	}
	return (this->first_name);
}

std::string Contact::get_last_name(int max_size)
{
	int	size = (int)this->last_name.length();
	std::string	substr;

	if (max_size > 0 && size > max_size)
	{
		substr = this->last_name.substr(0, 9);
		substr.push_back('.');
		return (substr);
	}
	return (this->last_name);
}

std::string	Contact::get_nickname(int max_size)
{
	int	size = this->nickname.length();
	std::string	substr;

	if (max_size >  0 && size > max_size)
	{
		substr = this->nickname.substr(0, max_size - 1);
		substr.push_back('.');
		return (substr);
	}
	return (this->nickname);
}

std::string	Contact::get_phone_number(int max_size)
{
	int	size = this->phone_number.length();
	std::string	substr;

	if (max_size > 0 && size > max_size)
	{
		substr = this->phone_number.substr(0, max_size - 1);
		substr.push_back('.');
		return (substr);
	}
	return (this->phone_number);
}

std::string	Contact::get_secret(int max_size)
{
	int	size = this->secret.length();
	std::string	substr;

	if (max_size > 0 && size > max_size)
	{
		substr = this->phone_number.substr(0, max_size - 1);
		substr.push_back('.');
		return (substr);
	}
	return (this->secret);
}

void	Contact::set_new(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->secret = secret;
}
