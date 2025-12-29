/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:53:41 by ntome             #+#    #+#             */
/*   Updated: 2025/12/29 18:05:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

int	main(void)
{
	MateriaSource *spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	
	IMateriaSource *spellBookCopy = new MateriaSource(*spellBook);
	
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	
	AMateria *tmp;
	Character *Bomboclat = new Character("Bomboclat");
	
	tmp = spellBookCopy->createMateria("cure");
	Bomboclat->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Bomboclat->equip(tmp);



	Character *BomboclatCopy = new Character(*Bomboclat);
	
	BomboclatCopy->use(1, *Bomboclat);
	BomboclatCopy->use(0, *Bomboclat);
	Bomboclat->unequip(1);
	delete tmp;


	ICharacter* darckvador = new Character("DarckVador");

	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	delete tmp;
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	delete tmp;
	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	delete tmp;

	ICharacter *spongebob = new Character("SpongeBob");
	darckvador->use(0, *spongebob);
	darckvador->use(1, *spongebob);
	spongebob->use(0, *darckvador);
	spongebob->use(1, *darckvador);

	delete BomboclatCopy;

	delete Bomboclat;

	delete spongebob;

	delete darckvador;

	delete spellBook;
	
	delete spellBookCopy;
	return (0);
}
