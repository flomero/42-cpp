/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:39:56 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 16:05:05 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		source[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
		source[i] = nullptr;
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.source[i])
			source[i] = other.source[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!source[i])
		{
			source[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i] && source[i]->getType() == type)
			return source[i]->clone();
	}
	return nullptr;
}
