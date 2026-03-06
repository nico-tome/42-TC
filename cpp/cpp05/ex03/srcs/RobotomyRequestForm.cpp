/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:16:48 by ntome             #+#    #+#             */
/*   Updated: 2026/03/06 17:21:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/color.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request Form", 72, 45), _target("default")
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm parameterized constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), _target(src._target)
{
	std::cout << YELLOW << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src.getTarget();
	if (this == &src)
		return *this;
	std::cout << BLUE << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void RobotomyRequestForm::executeAction(void) const
{
	std::cout << "🔧B🪛zz💥zz🔧💥zz🪛...⚙️⚙️⚙️ ";
	if (std::rand() % 2)
		std::cout << GREEN << this->getTarget() << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed on " << this->getTarget() << "." << RESET << std::endl;
}