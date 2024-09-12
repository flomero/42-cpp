/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:41 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 09:41:35 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << LOG "Dog default constructor called" RESET << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << LOG "Dog destructor called" RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << LOG "Dog copy constructor called" RESET << std::endl;
	static_cast<void>(other);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << LOG "Dog copy assignment operator called" RESET << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}