/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:11:32 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 19:32:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;

    public:
        Cat(void);
        Cat(const Cat& other);
        ~Cat(void);

        Cat&			operator=(const Cat& other);

        void	makeSound(void) const;
        void	setIdea(int idx, const std::string idea);
        std::string getIdea(int idx) const;
};

#endif