/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:35 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 14:50:18 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << LOG "Cat default constructor called" RESET << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << LOG "Cat copy constructor called" RESET << std::endl;
	brain = new Brain();
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << LOG "Cat copy assignment operator called" RESET << std::endl;
	if (this == &other)
		return *this;
	*brain = *other.brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << LOG "Cat destructor called" RESET << std::endl;
	delete brain;
}

Brain *Cat::getBrain() const
{
	return brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}