/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:35:31 by ntome             #+#    #+#             */
/*   Updated: 2026/03/05 12:38:13 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "color.hpp"

int main(void)
{
    Bureaucrat bureaucrat("bureaucrat", 31);

    /* TEST FORM WITH A GOOD GRADE */
    std::cout << std::endl << std::endl << "\e[32mTEST FORMS WITH A GOOD GRADE\e[0m" << std::endl << std::endl;

    Form form1("Form 1", 42, 42);
    Form form2("Form 2", 1, 1);
    Form form3("Form 3", 150, 150);
    Form form4("Form 4", 21, 21);

    /* TEST FORM BY CONSTRUCTOR COPY */
    std::cout << std::endl << std::endl << "\e[32mTEST FORMS BY CONSTRUCTOR COPY\e[0m" << std::endl << std::endl;

    Form form6(form1);

    /* TEST FORM BY ASSIGNATION COPY */
    std::cout << std::endl << std::endl << "\e[32mTEST FORMS BY ASSIGNATION COPY\e[0m" << std::endl << std::endl;

    Form form7 = form1;

    /* TEST FORM WITH A BAD GRADE */
    std::cout << std::endl << std::endl << "\e[32mTEST FORMS WITH A BAD GRADE\e[0m" << std::endl << std::endl;

    try{
        Form form8("Form 8", 42, -1);
        Form form9("Form 9", 151, 1);
        Form form10("Form 10", 53, 151);
        Form form11("Form 11", -2, 21);
    }
    catch (Form::GradeTooHighException &e) { std::cout << e.what() << std::endl; }
    catch (Form::GradeTooLowException &e) { std::cout << e.what() << std::endl; }

    /* TEST FORM print << Operator */
    std::cout << std::endl << std::endl << "\e[32mTEST FORM print << Operator\e[0m" << std::endl << std::endl;

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;
    std::cout << form4 << std::endl;
    std::cout << form6 << " (form6)" << std::endl;
    std::cout << form7 << " (form7)" << std::endl;

    /* TEST FORM beSigned() */
    std::cout << std::endl << std::endl << "\e[32mTEST FORM beSigned()\e[0m" << std::endl << std::endl;

    try {
        bureaucrat.signForm(form1);
        bureaucrat.signForm(form1);
        bureaucrat.signForm(form7);
        bureaucrat.signForm(form2);
    }
    catch (Form::GradeTooLowException &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl << std::endl << "\e[32mDESTROY\e[0m" << std::endl << std::endl;
}