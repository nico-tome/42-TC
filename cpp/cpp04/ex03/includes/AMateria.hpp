/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:39:27 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 17:58:50 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "Colors.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria &other);
		
		AMateria &operator=(const AMateria &other);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif