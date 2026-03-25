/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:52:04 by ntome             #+#    #+#             */
/*   Updated: 2026/03/22 15:34:52 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <stdexcept>

class Span
{
	private:
		std::vector<int>	_span;
		unsigned int		_size;
		unsigned int		_len;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &src);
		~Span(void);
		Span &operator=(const Span &src);

		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		class SingleValue : public std::exception {
            
            public:
                virtual const char *what() const throw();
        };

        class TooManyValues : public std::exception {
            
            public:
                virtual const char *what() const throw();
        };
};

#endif