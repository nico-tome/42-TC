/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:29:59 by ntome             #+#    #+#             */
/*   Updated: 2025/12/23 13:32:09 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Zombie.hpp"

Zombie*	newZombie( std::string name)
{
	Zombie	*new_zombie = new Zombie(name);
	return (new_zombie);
}
