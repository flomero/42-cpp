/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:33 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 10:26:27 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// can't compile because Animal is an abstract class now
	const Animal *meta = new Animal();
	delete meta;

	const Animal *dog = new Dog();
	dog->makeSound();
	delete dog;
	return 0;
}
