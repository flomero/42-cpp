/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:35 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 13:13:31 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << LOG "Cat default constructor called" RESET << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << LOG "Cat destructor called" RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << LOG "Cat copy constructor called" RESET << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << LOG "Cat copy assignment operator called" RESET << std::endl;
	static_cast<void>(other);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}