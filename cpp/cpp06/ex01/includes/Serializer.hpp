/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:28:41 by ntome             #+#    #+#             */
/*   Updated: 2026/03/03 15:40:16 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	std::string name;
	std::string last_name;
	int			age;
	std::string nationality;
};

class Serializer
{
	private:
		Serializer(void);

	public:
		virtual ~Serializer(void) = 0;
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &src);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif