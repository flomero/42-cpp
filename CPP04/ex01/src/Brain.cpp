/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:01:11 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 12:08:26 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << LOG "Brain default constructor called" RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << LOG "Brain destructor called" RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << LOG "Brain copy constructor called" RESET << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << LOG "Brain copy assignment operator called" RESET << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < ideasCount; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= ideasCount)
		return "Invalid index";
	return ideas[index];
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= ideasCount)
		return;
	ideas[index] = idea;
}
