/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:04:36 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:11:27 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
    protected:
        std::string	type;

    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();

        Animal&			operator=(const Animal& other);

        virtual void	makeSound() const;
        std::string		getType() const;
};

#endif
