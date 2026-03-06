/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:51:59 by ntome             #+#    #+#             */
/*   Updated: 2026/03/05 12:28:47 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/color.hpp"

Form::Form(void): _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << GREEN << "Form constructor called" << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << YELLOW << "Form copy constructor called" << RESET << std::endl;
	*this = src;
}

Form::~Form(void)
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

Form	&Form::operator=(const Form &src)
{
	this->_isSigned = src.getIsSigned();
	if (this == &src)
		return *this;
	std::cout << BLUE << "Form = operator called" << RESET << std::endl;
	return *this;
}

std::string const Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_isSigned;
}

int Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() <= this->getGradeToSign() && !this->_isSigned)
		this->_isSigned = true;
	else if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out
    << form.getName() << ", grade need to sign it : "
    << form.getGradeToSign() << ", grade need to execute it : "
    << form.getGradeToExecute() << ", is signed : "<< form.getIsSigned()
    << std::endl;
    return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}