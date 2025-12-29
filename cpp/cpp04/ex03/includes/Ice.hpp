/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:06:37 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 17:52:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Colors.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);

		AMateria* clone() const;
		void use(ICharacter& target);
		std::string const &getType() const;
};

#endif