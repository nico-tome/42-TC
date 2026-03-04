/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:43:49 by ntome             #+#    #+#             */
/*   Updated: 2026/03/04 09:03:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>
#include <color.hpp>

int	main(void)
{
	uintptr_t		serialized_data;
	Data			*deserialized_data;
	Data			data;

	data.name = "Nicolas";
	data.last_name = "Tome";
	data.age = 19;
	data.nationality = "French";

	std::cout << YELLOW << "Original data:" << RESET << std::endl << std::endl;
	std::cout << GREEN << "Name: " << data.name << RESET << std::endl;
	std::cout << GREEN << "Last name: " << data.last_name << RESET << std::endl;
	std::cout << GREEN << "Age: " << data.age << RESET << std::endl;
	std::cout << GREEN << "Nationality: " << data.nationality << RESET << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "Serializing data..." << RESET << std::endl << std::endl;
	serialized_data = Serializer::serialize(&data);

	std::cout << RED << "Serialized data: " << serialized_data << RESET << std::endl;
	
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "Deserializing data..." << RESET << std::endl << std::endl;
	deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << YELLOW << "Deserialized data:" << RESET << std::endl << std::endl;
	
	std::cout << CYAN << "Name: " << deserialized_data->name << RESET << std::endl;
	std::cout << CYAN << "Last name: " << deserialized_data->last_name << RESET << std::endl;
	std::cout << CYAN << "Age: " << deserialized_data->age << RESET << std::endl;
	std::cout << CYAN << "Nationality: " << deserialized_data->nationality << RESET << std::endl;
}