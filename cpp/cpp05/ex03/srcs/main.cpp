/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:35:31 by ntome             #+#    #+#             */
/*   Updated: 2026/03/06 18:11:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"
#include "color.hpp"

int main( void )
{
    std::string formName = "robotomy request";
    std::string target = "Bender";
    Intern  someRandomIntern;
    AForm*   rrf;
    try {
        // rrf = someRandomIntern.makeForm("robotomy", "Bender");
        rrf = someRandomIntern.makeForm(formName, target);
        if (!rrf)
            throw std::exception();
        Bureaucrat bureaucrat("ash", 2);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);
        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        for (size_t i = 0; i < 1000000000; i++);
        bureaucrat.executeForm(form2);
        for (size_t i = 0; i < 1000000000; i++);
        bureaucrat.executeForm(form2);
        for (size_t i = 0; i < 1000000000; i++);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    delete rrf;
    return 0;
}