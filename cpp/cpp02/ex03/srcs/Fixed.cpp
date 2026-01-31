/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:53:34 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 12:58:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void): fixed_point(0) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int value)
{
	this->fixed_point = value << this->bit;
}

Fixed::Fixed(const float value)
{
	this->fixed_point = roundf(value * (1 << this->bit));
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	if (this != &other)
		this->fixed_point = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

float	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->fixed_point--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->fixed_point;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->fixed_point;
	return (tmp);
}

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->fixed_point / (float)(1 << this->bit));
}

int	Fixed::toInt(void) const
{
	return (this->fixed_point >> this->bit);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &value)
{
	o << value.toFloat();
	return (o);
}
