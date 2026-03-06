/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:51:59 by ntome             #+#    #+#             */
/*   Updated: 2026/03/06 17:12:41 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/color.hpp"

AForm::AForm(void): _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << GREEN << "AForm constructor called" << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << YELLOW << "AForm copy constructor called" << RESET << std::endl;
	*this = src;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

AForm	&AForm::operator=(const AForm &src)
{
	this->_isSigned = src.getIsSigned();
	if (this == &src)
		return *this;
	std::cout << BLUE << "AForm = operator called" << RESET << std::endl;
	return *this;
}

std::string const AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

int AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() <= this->getGradeToSign() && !this->_isSigned)
		this->_isSigned = true;
	else if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
		this->executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out
    << form.getName() << ", grade need to sign it : "
    << form.getGradeToSign() << ", grade need to execute it : "
    << form.getGradeToExecute() << ", is signed : "<< form.getIsSigned()
    << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}