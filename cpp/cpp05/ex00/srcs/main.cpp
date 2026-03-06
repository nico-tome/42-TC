/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:35:31 by ntome             #+#    #+#             */
/*   Updated: 2026/03/05 11:36:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color.hpp"

int main(void)
{
    /* TEST BUREAUCRATS WITH A GOOD GRADE */
    std::cout << std::endl << std::endl << "\e[32mTEST BUREAUCRATS WITH A GOOD GRADE\e[0m" << std::endl << std::endl;

    Bureaucrat bureaucrat1("goodgrade 1", 42);
    Bureaucrat bureaucrat2("goodgrade 2", 1);
    Bureaucrat bureaucrat3("goodgrade 3", 150);
    Bureaucrat bureaucrat4("goodgrade 4", 21);

    /* TEST BUREAUCRATS BY CONSTRUCTOR COPY */
    std::cout << std::endl << std::endl << "\e[32mTEST BUREAUCRATS BY CONSTRUCTOR COPY\e[0m" << std::endl << std::endl;

    Bureaucrat bureaucrat5(bureaucrat4);

    /* TEST BUREAUCRATS BY ASSIGNATION COPY */
    std::cout << std::endl << std::endl << "\e[32mTEST BUREAUCRATS BY ASSIGNATION COPY\e[0m" << std::endl << std::endl;

    Bureaucrat bureaucrat6 = bureaucrat1;

    /* TEST BUREAUCRATS WITH A BAD GRADE */
    std::cout << std::endl << std::endl << "\e[32mTEST BUREAUCRATS WITH A BAD GRADE\e[0m" << std::endl << std::endl;

    try{
        Bureaucrat bureaucrat5("badgrade 1", -1);
        Bureaucrat bureaucrat6("badgrade 2", 0);
        Bureaucrat bureaucrat7("badgrade 3", 151);
        Bureaucrat bureaucrat8("badgrade 4", -123223);
    }
    catch (Bureaucrat::GradeTooHighException &e) { std::cout << e.what() << std::endl; }
    catch (Bureaucrat::GradeTooLowException &e) { std::cout << e.what() << std::endl; }

    std::cout << bureaucrat1 << std::endl;
    std::cout << bureaucrat2 << std::endl;
    std::cout << bureaucrat3 << std::endl;
    std::cout << bureaucrat4 << std::endl;
    std::cout << bureaucrat5 << " (bureaucrat5)" << std::endl;
    std::cout << bureaucrat6 << " (bureaucrat6)" << std::endl;

    /* TEST INCREMENT */
    std::cout << std::endl << std::endl << "\e[32mTEST INCREMENT\e[0m" << std::endl << std::endl;

    try {
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat2.incrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat3.incrementGrade();
        std::cout << bureaucrat3 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) { std::cout << e.what() << std::endl; }
    catch (Bureaucrat::GradeTooLowException &e) { std::cout << e.what() << std::endl; }

    /* TEST DECREMENT */
    std::cout << std::endl << std::endl << "\e[32mTEST DECREMENT\e[0m" << std::endl << std::endl;

    try {
        bureaucrat1.decrementGrade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat3.decrementGrade();
        std::cout << bureaucrat3 << std::endl;
        bureaucrat3.decrementGrade();
        std::cout << bureaucrat3 << std::endl;
        bureaucrat4.decrementGrade();
        std::cout << bureaucrat4 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) { std::cout << e.what() << std::endl; }
    catch (Bureaucrat::GradeTooLowException &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl << std::endl << "\e[32mDESTROY\e[0m" << std::endl << std::endl;
}