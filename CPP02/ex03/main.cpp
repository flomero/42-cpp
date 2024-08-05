/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:01 by flfische          #+#    #+#             */
/*   Updated: 2024/08/05 12:50:01 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(0, 1);
	Point c(1, 0);
	Point point1(0.5, 0.5);
	Point point2(1, 1);
	Point point3(0, 0);
	Point point4(-0.5, -0.5);
	Point point5(1.00001f, 0.0f);

	std::cout << "Point 1 is" << (bsp(a, b, c, point1) ? "\033[32m inside" : "\033[31m outside") << "\033[0m the triangle." << std::endl;
	std::cout << "Point 2 is" << (bsp(a, b, c, point2) ? "\033[32m inside" : "\033[31m outside") << "\033[0m the triangle." << std::endl;
	std::cout << "Point 3 is" << (bsp(a, b, c, point3) ? "\033[32m inside" : "\033[31m outside") << "\033[0m the triangle." << std::endl;
	std::cout << "Point 4 is" << (bsp(a, b, c, point4) ? "\033[32m inside" : "\033[31m outside") << "\033[0m the triangle." << std::endl;
	std::cout << "Point 5 is" << (bsp(a, b, c, point5) ? "\033[32m inside" : "\033[31m outside") << "\033[0m the triangle." << std::endl;
	return 0;
}
