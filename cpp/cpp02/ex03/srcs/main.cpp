/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:28:08 by ntome             #+#    #+#             */
/*   Updated: 2025/12/24 18:48:19 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

    Point a(1.0f, 1.0f);
    Point b(5.0f, 1.0f);
    Point c(3.0f, 4.0f);
    Point pt(3.0f, 2.0f);

    Point d(-2.0f, 4.0f);
    Point e(-4.0f, 0.0f);
    Point f(5.0f, -3.0f);
    Point pt1(-1.0f, 2.999f);

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

    return 0;
}
