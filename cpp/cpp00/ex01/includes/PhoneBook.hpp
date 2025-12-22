/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:04:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/22 16:42:27 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <cstring>
# include <cstdlib>
# include "Contact.hpp"

class	Phonebook
{
	private:
		int	size;
		Contact	contacts[8];

	public:
		Phonebook(void);
		~Phonebook(void);
		void	add_contact(void);
		void	search_contact(void);
		void	show_contact(int idx);
};

#endif 
