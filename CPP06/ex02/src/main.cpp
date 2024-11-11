/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:19:51 by flfische          #+#    #+#             */
/*   Updated: 2024/11/11 20:32:25 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

#ifndef DEBUG
#define DEBUG 0
#endif

Base *generate(void)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	int random = rand() % 3;

	if (random == 0)
	{
		if (DEBUG)
			std::cout << CYAN << "Created A" << RESET << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		if (DEBUG)
			std::cout << CYAN << "Created B" << RESET << std::endl;
		return new B();
	}
	else
	{
		if (DEBUG)
			std::cout << CYAN << "Created C" << RESET << std::endl;
		return new C();
	}
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;
		std::cout << "----------------" << std::endl;
	}
	return 0;
}