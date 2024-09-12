/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:41 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 13:30:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << LOG "Dog default constructor called" RESET << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << LOG "Dog copy constructor called" RESET << std::endl;
	brain = new Brain();
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << LOG "Dog copy assignment operator called" RESET << std::endl;
	if (this == &other)
		return *this;
	*brain = *other.brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << LOG "Dog destructor called" RESET << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}
