/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:07:37 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 18:03:57 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	fixed_point;
		static const int	bit = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);

		Fixed	&operator=(const Fixed &other);

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		float	operator+(const Fixed &other) const;
		float	operator-(const Fixed &other) const;
		float	operator*(const Fixed &other) const;
		float	operator/(const Fixed &other) const;

		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		Fixed	static min(Fixed &f1, Fixed &f2);
		Fixed	static max(Fixed &f1, Fixed &f2);
		Fixed	static min(const Fixed &f1, const Fixed &f2);
		Fixed	static max(const Fixed &f1, const Fixed &f2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &value);

#endif
