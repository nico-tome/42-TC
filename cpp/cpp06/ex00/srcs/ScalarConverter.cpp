/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:43:08 by ntome             #+#    #+#             */
/*   Updated: 2026/03/13 09:10:45 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <color.hpp>

ScalarConverter::ScalarConverter(void) {
	std::cout << GREEN << "ScalarConverter default constructor called" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
	std::cout << YELLOW << "ScalarConverter copy constructor called" << RESET << std::endl;
	*this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	if (this == &src)
		return (*this);
	std::cout << BLUE << "ScalarConverter copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	ScalarConverter::convert(const std::string src) {
	char		*convert_end;
	long int	int_val;
	float		float_val;
	double		double_val;

	if (src == "-inff" || src == "-inf")
	{
		std::cout << PURPLE << "char: impossible" << RESET << std::endl;
		std::cout << YELLOW << "int: impossible" << RESET << std::endl;
		std::cout << CYAN << "float: -inff" << RESET << std::endl;
		std::cout << BLUE << "double: -inf" << RESET << std::endl;
		return ;
	}
	if (src == "+inff" || src == "+inf")
	{
		std::cout << PURPLE << "char: impossible" << RESET << std::endl;
		std::cout << YELLOW << "int: impossible" << RESET << std::endl;
		std::cout << CYAN << "float: +inff" << RESET << std::endl;
		std::cout << BLUE << "double: +inf" << RESET << std::endl;
		return ;
	}
	if (src == "nanf" || src == "nan")
	{
		std::cout << PURPLE << "char: impossible" << RESET << std::endl;
		std::cout << YELLOW << "int: impossible" << RESET << std::endl;
		std::cout << CYAN << "float: nanf" << RESET << std::endl;
		std::cout << BLUE << "double: nan" << RESET << std::endl;
		return ;
	}

	
	if (src.length() == 1 && (src[0] < '0' || src[0] > '9'))
	{
		if (src[0] >= ' ' && src[0] <= '~')
			std::cout << PURPLE << "char: '" << src[0] << "'" << RESET << std::endl;
		else
			std::cout << PURPLE << "char: Non displayable" << RESET << std::endl;
		std::cout << YELLOW << "int: " << static_cast<int>(src[0]) << RESET << std::endl;
		std::cout << CYAN << "float: " << static_cast<float>(src[0]) << ".0f" << RESET << std::endl;
		std::cout << BLUE << "double: " << static_cast<double>(src[0]) << ".0" << RESET << std::endl;
		return ;
	}
	
	int_val = std::strtol(src.c_str(), &convert_end, 10);
	if (int_val <= INT_MAX && int_val >= INT_MIN && *convert_end == '\0')
	{
		if (int_val >= ' ' && int_val <= '~')
			std::cout << PURPLE << "char: '" << static_cast<char>(int_val) << "'" << RESET << std::endl;
		else
			std::cout << PURPLE << "char: Non displayable" << RESET << std::endl;
		std::cout << YELLOW << "int: " << int_val << RESET << std::endl;
		std::cout << CYAN << "float: " << static_cast<float>(int_val) << ".0f" << RESET << std::endl;
		std::cout << BLUE << "double: " << static_cast<double>(int_val) << ".0" << RESET << std::endl;
		return ;
	}
	
	bool	has_point = false;
	float_val = std::strtof(src.c_str(), &convert_end);
	for (int i = 0; src[i]; i++)
	{
		if (src[i] == '.')
			has_point = true;
	}
	if (has_point && *convert_end == 'f' && *(convert_end + 1) == '\0')
	{
		if (static_cast<int>(float_val) >= ' ' && static_cast<int>(float_val) <= '~')
			std::cout << PURPLE << "char: '" << static_cast<char>(float_val) << "'" << RESET << std::endl;
		else if (float_val >= 0 && float_val <= 127)
			std::cout << PURPLE << "char: Non displayable" << RESET << std::endl;
		else
			std::cout << PURPLE << "char: impossible" << RESET << std::endl;

		if (float_val <= static_cast<float>(INT_MAX) && float_val >= static_cast<float>(INT_MIN))
			std::cout << YELLOW << "int: " << static_cast<int>(float_val) << RESET << std::endl;
		else
			std::cout << YELLOW << "int: impossible" << RESET << std::endl;
		
		if (float_val > FLT_MAX || float_val < -FLT_MAX)
			std::cout << CYAN << "float: impossible" << RESET << std::endl;
		else
			std::cout << CYAN << "float: " << std::fixed << std::setprecision(1) << float_val << "f" << RESET << std::endl;
		
		if (float_val > DBL_MAX || float_val < -DBL_MAX)
			std::cout << BLUE << "double: impossible" << RESET << std::endl;
		else
			std::cout << BLUE << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(float_val) << RESET << std::endl;
		return ;
	}
	
	double_val = std::strtod(src.c_str(), &convert_end);
	if (*convert_end == '\0')
	{
		if (static_cast<int>(double_val) >= ' ' && static_cast<int>(double_val) <= '~')
			std::cout << PURPLE << "char: '" << static_cast<char>(double_val) << "'" << RESET << std::endl;
		else if (double_val >= 0 && double_val <= 127)
			std::cout << PURPLE << "char: Non displayable" << RESET << std::endl;
		else
			std::cout << PURPLE << "char: impossible" << RESET << std::endl;

		if (double_val <= INT_MAX && double_val >= INT_MIN)
			std::cout << YELLOW << "int: " << static_cast<int>(double_val) << RESET << std::endl;
		else
			std::cout << YELLOW << "int: impossible" << RESET << std::endl;
		
		if (double_val > FLT_MAX || double_val < -FLT_MAX)
			std::cout << CYAN << "float: impossible" << RESET << std::endl;
		else
			std::cout << CYAN << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(double_val) << "f" << RESET << std::endl;
		
		if (double_val > DBL_MAX || double_val < -DBL_MAX)
			std::cout << BLUE << "double: impossible" << RESET << std::endl;
		else
			std::cout << BLUE << "double: " << std::fixed << std::setprecision(1) << double_val << RESET << std::endl;
		return ;
	}

	std::cout << PURPLE << "char: impossible" << RESET << std::endl;
	std::cout << YELLOW << "int: impossible" << RESET << std::endl;
	std::cout << CYAN << "float: impossible" << RESET << std::endl;
	std::cout << BLUE << "double: impossible" << RESET << std::endl;
}