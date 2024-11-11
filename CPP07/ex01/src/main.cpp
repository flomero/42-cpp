/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:53:55 by flfische          #+#    #+#             */
/*   Updated: 2024/11/11 21:58:54 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

void printInt(int const &i)
{
	std::cout << i << std::endl;
}

void printChar(char const &c)
{
	std::cout << c << std::endl;
}

void printString(std::string const &s)
{
	std::cout << s << std::endl;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	iter(intArray, 5, printInt);
	std::cout << std::endl;
	iter(charArray, 5, printChar);
	std::cout << std::endl;
	iter(stringArray, 5, printString);
	return 0;
}
