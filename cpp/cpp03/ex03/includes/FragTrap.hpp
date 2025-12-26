/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:17:34 by ntome             #+#    #+#             */
/*   Updated: 2025/12/26 01:20:48 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);

        void    attack(const std::string &target);
        void    highFivesGuys(void);
};

#endif