/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/23 16:38:41 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	is_s2(std::string str, int i, std::string s1)
{
	for (int j = s1.length() - 1; j > 0; j--) {
		if (str[i + j] != s1[j])
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	std::string	FileName;
	std::string	NewFileName;
	std::string	Buffer;
	std::string	s1;
	std::string	s2;

	if (ac != 4)
	{
		std::cout << "Need: ./SedIsForLosers <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	FileName = av[1];
	NewFileName = FileName + ".replace";
	s1 = av[2];
	s2 = av[3];

	std::ofstream	MyFile(NewFileName.c_str());
	std::ifstream	MyReadFile(FileName.c_str());

	if (MyFile.fail() || MyReadFile.fail()) {
		std::cout << "Error while opening files." << std::endl;
		if (!MyFile.fail())
			MyFile.close();
		if (!MyReadFile.fail())
			MyReadFile.close();
		return (1);
	}

	while (std::getline(MyReadFile, Buffer))
	{
		for (int i = 0; i < (int)Buffer.length(); i++)
		{
			if (Buffer[i] == s1[0] && is_s2(Buffer, i, s1))
			{
				i += s1.length() - 1;
				MyFile << s2;
			}
			else
				MyFile << Buffer[i];
		};
	}

	MyFile.close();
	MyReadFile.close();
	return (0);
}
