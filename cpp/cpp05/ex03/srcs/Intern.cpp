/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:44:14 by ntome             #+#    #+#             */
/*   Updated: 2026/03/06 18:06:58 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/color.hpp"

Intern::Intern(void)
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << YELLOW << "Intern copy constructor called" << RESET << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	std::cout << BLUE << "Intern copy assignment operator called" << RESET << std::endl;
	return *this;
}

AForm *Intern::makeForm(std::string &formName, std::string &target) const
{
	if (target.empty())
	{
		std::cout << "Error: Target cannot be empty." << std::endl;
		return NULL;
	}
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formCreators[3])(std::string const &target) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cout << "Error: Form name \"" << formName << "\" is not recognized." << std::endl;
	return NULL;
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) const
{
	return new PresidentialPardonForm(target);
}