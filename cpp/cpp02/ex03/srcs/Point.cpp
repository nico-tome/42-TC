/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:21:04 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 18:51:33 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::~Point(void) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &other)
{
	*this = other;
}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

float	Point::getX(void) const
{
	return (this->x.toFloat());
}

float	Point::getY(void) const
{
	return (this->y.toFloat());
}

float	Point::cross(const Point &p1, const Point &p2) const
{
	return ((p2.x - p1.x) * (this->y - p1.y) - (p2.y - p1.y) * (this->x - p1.x));
}
