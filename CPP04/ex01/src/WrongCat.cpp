/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:35 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 13:16:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << LOG "WrongCat default constructor called" RESET << std::endl;
	type = "Cat";
}

WrongCat::~WrongCat()
{
	std::cout << LOG "WrongCat destructor called" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << LOG "WrongCat copy constructor called" RESET << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << LOG "WrongCat copy assignment operator called" RESET << std::endl;
	static_cast<void>(other);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}