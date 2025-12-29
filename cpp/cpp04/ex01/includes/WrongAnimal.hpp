/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:12:18 by ntome             #+#    #+#             */
/*   Updated: 2025/12/27 18:12:26 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
    protected:
        std::string	type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal();

        WrongAnimal&			operator=(const WrongAnimal& other);

        virtual void	makeSound() const;
        std::string		getType() const;
};

#endif