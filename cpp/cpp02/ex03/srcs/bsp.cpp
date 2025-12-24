/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:38:12 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 18:45:39 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	c1 = point.cross(a, b);
	float	c2 = point.cross(b, c);
	float	c3 = point.cross(c, a);

	bool	pos = (c1 < 0.f) || (c2 < 0.f) || (c3 < 0.f);
	bool	neg = (c1 > 0.f) || (c2 > 0.f) || (c3 > 0.f);

	return !(neg && pos);
}
