/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:07:52 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 17:45:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Colors.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);

		AMateria* clone() const;
		void use(ICharacter& target);
		std::string const &getType() const;
};

#endif