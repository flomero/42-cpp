/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:02:27 by flfische          #+#    #+#             */
/*   Updated: 2024/11/13 16:04:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"
#define HEADER(X) std::cout << CYAN << X << RESET << std::endl

Span generateRandomSpan(unsigned int n, int min = 0, int max = 1000)
{
	Span sp = Span(n);

	for (unsigned int i = 0; i < n; i++)
		sp.addNumber(rand() % (max - min + 1) + min);
	return sp;
}

void testSpan(unsigned int n, int min = 0, int max = 1000)
{
	HEADER("Test with " << n << " random numbers");
	Span sp = generateRandomSpan(n, min, max);
	if (sp.size() < 100)
		std::cout << sp << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptionFull()
{
	HEADER("Test Exception (Span is full)");
	Span sp = Span(1);
	try
	{
		sp.addNumber(42);
		sp.addNumber(42);
		std::cout << sp << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testExceptionEmpty()
{
	HEADER("Test Exception (Span is empty)");
	Span sp = Span(1);
	try
	{
		sp.shortestSpan();
		std::cout << sp << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testIterator()
{
	HEADER("Test with iterator");
	std::vector<int> v = {1, 2, 3, 4, 5};
	Span sp = Span(5);
	sp.addNumber(v.begin(), v.end());
	std::cout << sp << std::endl;
}

int main()
{
	srand(time(NULL));
	testSpan(10);
	testSpan(100);
	testSpan(1000);
	testSpan(10000);
	testSpan(10000, -100000, 100000);

	testExceptionFull();
	testExceptionEmpty();
	testIterator();
	return 0;
}
