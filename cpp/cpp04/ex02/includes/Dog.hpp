/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:12:07 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 19:32:27 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;

    public:
        Dog(void);
        Dog(const Dog& other);
        ~Dog(void);

        Dog&			operator=(const Dog& other);

        void	makeSound(void) const;
        void	setIdea(int idx, const std::string idea);
        std::string getIdea(int idx) const;
};

#endif