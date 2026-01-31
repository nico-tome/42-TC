/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 13:34:44 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool    bsp(Point const &a, Point const &b, Point const &c, Point const &point);

int main(void) {

    Point a(1.0f, 1.0f);
    Point b(5.0f, 4.0f);
    Point c(3.0f, 5.0f);
    Point pt(2.0f,2.0f);

    Point d(-2.0f, 4.0f);
    Point e(-4.0f, 0.0f);
    Point f(5.0f, -3.0f);
    Point pt1(-1.0f, 2.999f);

	Point g(1.0f, 4.0f);
	Point h(2.0f, 4.0f);
	Point i(2.0f, 1.0f);
	Point pt2(200.0f, 200.f);

	std::cout << "\e[32m\nSupposed to be: true / inside\e[0m" << std::endl << std::endl;
    std::cout << "\e[35m[Tirangle Points 1: " << a.getX() << " " << a.getY() << " ; "
    << b.getX() << " " << b.getY() << " ; "
    << c.getX() << " " << c.getY()
    << "]\e[0m" << std::endl;
    if (bsp(a, b, c, pt)) {
        std::cout << "\e[35m[Point1: " << pt.getX() << " " << pt.getY() << "]\e[0m" << std::endl;
        std::cout << "\e[32mtrue\e[0m" << std::endl;
    }
    else {
        std::cout << "\e[35m[Point1: " << pt.getX() << " " << pt.getY() << "]\e[0m" << std::endl;
        std::cout << "\e[31mfalse\e[0m" << std::endl;
    }

	std::cout << "\n\e[31mSupposed to be: false / on edge\e[0m" << std::endl;
    std::cout << std::endl << "\e[35m[Tirangle Points 2: " << d.getX() << " " << d.getY() << " ; "
    << e.getX() << " " << e.getY() << " ; "
    << f.getX() << " " << f.getY()
    << "]\e[0m" << std::endl;
    if (bsp(d, e, f, pt1)) {
        std::cout << "\e[35m[Point1: " << pt1.getX() << " " << pt1.getY() << "]\e[0m" << std::endl;
        std::cout << "\e[32mtrue\e[0m" << std::endl;
    }
    else {
        std::cout << "\e[35m[Point1: " << pt1.getX() << " " << pt1.getY() << "]\e[0m" << std::endl;
        std::cout << "\e[31mfalse\e[0m" << std::endl;
    }

	std::cout << "\n\e[31mSupposed to be: false / outside\e[0m" << std::endl;
	std::cout << std::endl << "\e[35m[Tirangle Points 3: " << g.getX() << " " << g.getY() << " ; "
    << h.getX() << " " << h.getY() << " ; "
    << i.getX() << " " << i.getY()
    << "]\e[0m" << std::endl;
    if (bsp(g, h, i, pt2)) {
        std::cout << "\e[35m[Point1: " << pt2.getX() << " " << pt2.getY() << "]\e[0m" << std::endl;
        std::cout << "\e[32mtrue\e[0m" << std::endl;
    }
    else {
        std::cout << "\e[35m[Point1: " << pt2.getX() << " " << pt2.getY() << "]\e[0m" << std::endl;
        std::cout << "\e[31mfalse\e[0m" << std::endl;
    }

    return 0;
}
