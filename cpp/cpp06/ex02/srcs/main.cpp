/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:31:37 by ntome             #+#    #+#             */
/*   Updated: 2026/03/04 09:52:04 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.hpp"
#include <cstdlib>

Base *generate(void)
{
    int i = rand() % 3;
	switch (i)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if (A *a = dynamic_cast<A *>(p)) {
		std::cout << BLUE << "A" << RESET << std::endl;
		(void)a;
	}
	else if (B *b = dynamic_cast<B *>(p)) {
		std::cout << GREEN << "B" << RESET << std::endl;
		(void)b;
	}
	else if (C *c = dynamic_cast<C *>(p)) {
		std::cout << YELLOW << "C" << RESET << std::endl;
		(void)c;
	}
	else
		std::cout << RED << "Unknown type" << RESET << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << BLUE << "A" << RESET << std::endl;
        (void)a;
		return;
    }
    catch(std::exception &e) {}

    try {
        B &b = dynamic_cast<B &>(p);
        std::cout << GREEN << "B" << RESET << std::endl;
        (void)b;
		return;
    }
    catch(std::exception &e) {}

    try {
        C &c = dynamic_cast<C &>(p);
        std::cout << YELLOW << "C" << RESET << std::endl;
        (void)c;
		return;
    }
    catch(std::exception &e) {}

	std::cout << RED << "Unknown type" << RESET << std::endl;
}

int main(int ac, char **av)
{
	srand(time(NULL));
	if (ac != 2)
	{
		std::cerr << RED << "Usage: " << av[0] << " <1-9>" << RESET << std::endl;
		return 1;
	}
	int n = std::atoi(av[1]);
	if (n < 1 || n > 9)
	{
		std::cerr << RED << "Please provide a number between 1 and 9" << RESET << std::endl;
		return 1;
	}
	for (int i = 0; i < n; ++i)
	{
		Base *obj = generate();
		std::cout << "Identifying with pointer: ";
		identify(obj);
		std::cout << "Identifying with reference: ";
		identify(*obj);
		delete obj;
	}
	return 0;
}