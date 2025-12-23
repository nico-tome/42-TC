/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 00:12:08 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(void)
{
    Harl harl;
    std::cout << "DEBUG" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    std::cout << "INFO" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    std::cout << "WARNING" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    std::cout << "ERROR" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    std::cout << "NO EXIST LEVEL" << std::endl;
    harl.complain("NO EXIST LEVEL");
}
