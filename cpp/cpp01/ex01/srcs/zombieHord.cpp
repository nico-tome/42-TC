/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:46:47 by ntome             #+#    #+#             */
/*   Updated: 2025/12/23 14:11:53 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHord(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie*	new_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		new_horde[i].update_name(name);
	return (new_horde);
}
