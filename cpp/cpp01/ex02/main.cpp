/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:46:26 by ntome             #+#    #+#             */
/*   Updated: 2025/12/23 14:56:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "ADRESS:" << std::endl << "	str: " << &str << std::endl << "	PTR: " << stringPTR << std::endl << "	REF: " << &stringREF << std::endl;
	std::cout << "VALUE:" << std::endl << "	str: " << str << std::endl << "	PTR: " << *stringPTR << std::endl << "	REF: " << stringREF << std::endl;
	return (0);
}
