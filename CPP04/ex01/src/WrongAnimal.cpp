/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:46 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 15:41:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << LOG "WrongAnimal default constructor called" RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << LOG "WrongAnimal destructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << LOG "WrongAnimal copy constructor called" RESET << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << LOG "WrongAnimal copy assignment operator called" RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random undefined noises..." << std::endl;
}
