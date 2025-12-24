/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:05:50 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 18:48:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point(void);
		~Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		
		Point	&operator=(const Point &other);

		float	cross(const Point &p1, const Point &p2) const;
		float	getX(void) const;
		float	getY(void) const;
};

#endif
