/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:10:01 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 18:02:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <cstdlib>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
	
	public:
		Character(void);
		Character(std::string const & name);
		~Character();
		Character(const Character &other);
		Character &operator=(const Character &other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif