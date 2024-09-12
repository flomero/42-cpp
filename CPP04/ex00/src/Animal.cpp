/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:46 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 15:41:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(const Animal &other)
{
	type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
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
