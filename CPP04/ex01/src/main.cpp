/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:33 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 17:06:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete (i);
	delete (j);
	delete (meta);

	Dog dog;
	Cat cat;
	dog.makeSound();
	cat.makeSound();
	std::cout << "-----------------------------------" << std::endl;
	WrongAnimal *wrongCat = new WrongCat();
	wrongCat->makeSound();
	delete (wrongCat);
	return 0;
}
