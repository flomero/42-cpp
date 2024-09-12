/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:46 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 09:47:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << LOG "Animal default constructor called" RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << LOG "Animal destructor called" RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << LOG "Animal copy constructor called" RESET << std::endl;
	type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << LOG "Animal copy assignment operator called" RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Random undefined noises..." << std::endl;
}

