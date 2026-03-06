/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:35:33 by ntome             #+#    #+#             */
/*   Updated: 2026/03/06 18:09:21 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <AForm.hpp>
# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <PresidentialPardonForm.hpp>

class Intern
{
	private:
		AForm* createShrubberyCreationForm(std::string const &target) const;
		AForm* createRobotomyRequestForm(std::string const &target) const;
		AForm* createPresidentialPardonForm(std::string const &target) const;
	
	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);
		Intern &operator=(const Intern &src);
		AForm* makeForm(std::string &formName, std::string &target) const;
};

#endif