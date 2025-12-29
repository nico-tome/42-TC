/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:04:36 by ntome             #+#    #+#             */
/*   Updated: 2025/12/28 14:33:35 by ntome            ###   ########.fr       */
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

        virtual void	makeSound() const = 0;
        std::string		getType() const;
};

#endif
