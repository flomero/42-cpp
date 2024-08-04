/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:01 by flfische          #+#    #+#             */
/*   Updated: 2024/08/04 12:15:12 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "------------------------------\n"
			  << "Additional tests (not in the subject)\n";
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	Fixed c(42);
	Fixed d(2.5f);
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;
	std::cout << "Comparisons\n";
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a > a) << std::endl;
	std::cout << (a < a) << std::endl;
	std::cout << (a >= a) << std::endl;
	return 0;
}
