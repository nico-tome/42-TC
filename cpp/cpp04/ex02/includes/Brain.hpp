/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:20:58 by ntome             #+#    #+#             */
/*   Updated: 2025/12/28 13:54:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain(void);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain(void);

        std::string getIdea(int idx) const;
        void setIdea(int idx, const std::string idea);
};

#endif