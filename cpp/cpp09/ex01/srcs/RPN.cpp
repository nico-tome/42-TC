/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:03:56 by ntome             #+#    #+#             */
/*   Updated: 2026/03/26 18:50:26 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include "../includes/color.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src) {
		this->_data = std::stack<double>(src._data);
	}
	return (*this);
}

void	RPN::calculate(std::string data)
{
	int		a;
	int		b;
	bool	needSpace = false;
	
	for (int i = 0; i < (int)data.length(); i++) {
		if (std::isdigit(data[i]) && !needSpace) {
			this->_data.push((data[i] - '0'));
			needSpace = true;
		}
		else if (!needSpace && (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/') && this->_data.size() > 1) {
			needSpace = true;
			a = this->_data.top();
			this->_data.pop();
			b = this->_data.top();
			this->_data.pop();
			if (data[i] == '+')
				this->_data.push(b + a);
			else if (data[i] == '-')
				this->_data.push(b - a);
			else if (data[i] == '*')
				this->_data.push(b * a);
			else if (data[i] == '/') {
				if (a == 0) {
					std::cout << RED << "Error: division by 0." << RESET << std::endl;
					return ;
				}
				else
					this->_data.push(b / a);
			}
		}
		else if (data[i] == ' ' && needSpace)
			needSpace = false;
		else {
			std::cout << RED << "Error: bad input '" << data[i] << "'" << RESET << std::endl;
			return ;
		}
	}
	if (this->_data.size() != 1)
		std::cout << RED << "Error: more than one element in the stack after the calculation." << RESET << std::endl;
	else
		std::cout << GREEN << this->_data.top() << RESET << std::endl;
}