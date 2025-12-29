/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:55:17 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 18:04:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Colors.hpp"
# include <cstdlib>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_inventory[4];
	
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif