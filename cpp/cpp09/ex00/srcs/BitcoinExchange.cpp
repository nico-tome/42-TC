/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:55:22 by ntome             #+#    #+#             */
/*   Updated: 2026/04/03 14:12:47 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "color.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) 
{
	*this  = src;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this == &src)
		return (*this);
	this->_data = std::map<std::string, float>(src._data);
	return (*this);
}

void	BitcoinExchange::loadData(std::string path)
{
	if (path.length() <= 4)
		throw std::runtime_error(ERR_FILE_FORMAT);
	if (path.compare(path.length() - 4, 4, ".csv") != 0)
		throw std::runtime_error(ERR_FILE_FORMAT);
	
	std::ifstream	file(path.c_str());
	std::string		line;
	std::string		date;
	std::string		value;

	if (!file.is_open())
		throw std::runtime_error(ERR_FILE_OPEN);
	
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error(ERR_FILE_HEADER);
	while (std::getline(file, line))
	{
		if ((int)line.find(",") == -1)
			throw std::runtime_error(ERR_LINE_FORMAT);
		date = line.substr(0, line.find(","));
		if (!checkDate(date))
			throw std::runtime_error(ERR_DATE);
		value = line.substr(line.find(",") + 1, line.length());
		if (!checkValue(value))
			throw std::runtime_error(ERR_VALUE);
		this->_data[date] = std::strtof(value.c_str(), NULL);
	}
}

bool	BitcoinExchange::checkDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++) {
		if (!std::isdigit(date[i]))
			return (false);
		if (i == 3 || i == 6)
			i++;
	}
	
	year = std::atoi((date.substr(0, 4)).c_str());
	month = std::atoi((date.substr(5, 7)).c_str());
	day = std::atoi((date.substr(8, 10)).c_str());

	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day >= 32)
			return (false);
	}
	if (month == 2) {
		if (day > 29)
			return (false);
		if (day == 29) {
			if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
				return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::checkValue(std::string value)
{
	bool	isFloat = false;
	bool	endPoint = false;

	for (int i = 0; i < (int)value.length(); i++) {
		if (!std::isdigit(value[i])) {
			if (value[i] == '.') {
				if (isFloat)
					return (false);
				isFloat = true;
				endPoint = true;
			}
			else
				return (false);
		}
		else
			endPoint = false;
	}
	if (isFloat && endPoint)
		return (false);
	return (true);
}

void	BitcoinExchange::printExchange(std::string path)
{
	std::ifstream	file(path.c_str());
	std::string		line;
	std::string		date;
	float			value;

	if (!file.is_open())
		throw std::runtime_error(ERR_FILE_OPEN);
	
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error(ERR_FILE_HEADER);
	while (std::getline(file, line))
	{
		if ((int)line.find(" | ") == -1)
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
		else {
			date = line.substr(0, line.find(" | "));
			if (!checkDate(date))
				std::cerr << RED << "Error: bad date => " << date << RESET << std::endl;
			value = std::strtof((line.substr(line.find(" | ") + 3, line.length())).c_str(), NULL);
			if (value > 1000)
				std::cerr << RED << "Error: " << ERR_NUM << " " << value << " > 1000" << RESET << std::endl;
			else if (value < 0)
				std::cerr << RED << "Error: " << ERR_NEG << " " << value << " < 0" << RESET << std::endl;
			else {
				std::cout << GREEN << date << RESET << " => " << YELLOW << value << RESET << " = " << CYAN << (value * this->_data[getCloseDate(date)]) << RESET << std::endl;
			}
		}
	}
}

std::string	BitcoinExchange::getCloseDate(std::string date)
{
	std::map<std::string, float>::const_iterator it = this->_data.lower_bound(date);

	if (it != this->_data.end() && it->first == date)
		return (it->first);
	if (it == this->_data.begin())
		return (it->first);
    --it;
    return (it->first);
}