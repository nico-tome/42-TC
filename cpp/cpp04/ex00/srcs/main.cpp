/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:25:39 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Color.hpp"

int main(void)
{
    std::cout << "----- Correct Animals -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;

    std::cout << "Type of meta: " << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << "Type of dog: " << dog->getType() << std::endl;
    dog->makeSound();
    std::cout << "Type of cat: " << cat->getType() << std::endl;
    cat->makeSound();

    std::cout << "\n----- Wrong Animals -----" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << "Type of wrongMeta: " << wrongMeta->getType() << std::endl;
    wrongMeta->makeSound();
    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    
    return (0);
}