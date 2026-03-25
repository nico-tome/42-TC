/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:42:41 by ntome             #+#    #+#             */
/*   Updated: 2026/03/25 17:28:19 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack(void);
		MutantStack(const MutantStack &src);
		~MutantStack(void);
		MutantStack &operator=(const MutantStack &src);
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();
};

# include "MutantStack.tpp"

#endif