/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:13:49 by ntome             #+#    #+#             */
/*   Updated: 2026/03/22 15:40:10 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include "color.hpp"

Span::Span(void)
{
	this->_size = 0;
	this->_len = 0;
	std::cout << GREEN << "Span default constructor called. Actual size: 0 Size: 0" << RESET << std::endl;
}

Span::Span(unsigned int N)
{
	this->_span.reserve(N);
	this->_size = N;
	this->_len = 0;
	std::cout << GREEN << "Span constructor called. Actual size: 0 Size: " << N << RESET << std::endl;
}

Span::Span(const Span &src)
{
	this->_len = 0;
	*this = src;
	std::cout << YELLOW << "Span copy contructor called." << RESET << std::endl;
}

Span::~Span(void)
{
	std::cout << RED << "Span destructor called." << RESET << std::endl;
}

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	this->_span.reserve(src._size);
	this->_size = src._size;
	this->_len = 0;
	for (unsigned int i = 0; i < src._len; i++)
		this->addNumber(src._span[i]);
	std::cout << BLUE << "Span = operator called." << RESET << std::endl;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_len + 1 <= this->_size) {
		this->_span.push_back(n);
		this->_len++;
	}
	else
		throw Span::TooManyValues();
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (this->_span.size() + std::distance(start, end) > this->_size)
		throw Span::TooManyValues();
	this->_span.insert(this->_span.end(), start, end);
}

int		Span::shortestSpan(void)
{
    if (this->_span.size() <= 1)
        throw Span::SingleValue();
    std::vector<int> tmp = this->_span;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++) {
        int tmp_span = tmp[i] - tmp[i - 1];
        if (tmp_span < min)
            min = tmp_span;
    }
    return min;
}

int		Span::longestSpan(void)
{
	if (this->_len <= 1)
		throw Span::SingleValue();
	std::vector<int>	tmp = this->_span;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::TooManyValues::what() const throw()
{
	return ("Too much values !");
}

const char *Span::SingleValue::what() const throw()
{
	return ("Not enough values !");
}
