/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:07:37 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 16:41:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	fixed_point;
		static const int	bit = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed	&operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
