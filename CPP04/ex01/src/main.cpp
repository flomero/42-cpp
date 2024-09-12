/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:33 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 14:50:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "-------" << std::endl;
	Dog test;
	{
		std::cout << "-------" << std::endl;
		Dog tmp(test);
		std::cout << "-------" << std::endl;
	}
	std::cout << "-------" << std::endl;

	test.getBrain()->setIdea(0, "I'm a dog");
	{
		Dog tmp = test;
		std::cout << tmp.getBrain()->getIdea(0) << std::endl;
		tmp.getBrain()->setIdea(0, "I'm a cat");
		std::cout << tmp.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << test.getBrain()->getIdea(0) << std::endl;

	return 0;
}
