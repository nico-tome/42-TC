/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:00:39 by ntome             #+#    #+#             */
/*   Updated: 2026/03/26 18:25:41 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <cstdlib>
# include <iostream>

class RPN
{
	private:
		std::stack<double>	_data;
	
	public:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);
		RPN	&operator=(const RPN &src);

		void	calculate(std::string data);
};

#endif