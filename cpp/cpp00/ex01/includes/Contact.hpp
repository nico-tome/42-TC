/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:24:48 by ntome             #+#    #+#             */
/*   Updated: 2025/12/22 16:15:28 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;

	public:
		Contact(void);
		~Contact(void);
		void	set_new(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret);
		std::string	get_first_name(int max_size);
		std::string	get_last_name(int max_size);
		std::string	get_nickname(int max_size);
		std::string	get_phone_number(int max_size);
		std::string	get_secret(int max_size);
};

#endif
