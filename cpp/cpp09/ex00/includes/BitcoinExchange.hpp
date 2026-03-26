/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:58:53 by ntome             #+#    #+#             */
/*   Updated: 2026/03/26 16:47:39 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

# define ERR_FILE_FORMAT "Invalid file format (.csv only)."
# define ERR_FILE_OPEN "File can't be open."
# define ERR_FILE_HEADER "Wrong file header."
# define ERR_LINE_FORMAT "Wrong line format."
# define ERR_DATE "Wrong date."
# define ERR_VALUE "Wrong value."
# define ERR_NEG "not a positive number."
# define ERR_NUM "too large a number."
# define ERR_INPUT "bad input"

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
	
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void	loadData(std::string path);
		bool	checkDate(std::string date);
		bool	checkValue(std::string value);
		void	printExchange(std::string path);
		std::string	getCloseDate(std::string date);
};

#endif