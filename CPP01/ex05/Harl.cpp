/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:20 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 13:58:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_complaints[0] = &Harl::debug;
	_complaints[1] = &Harl::info;
	_complaints[2] = &Harl::warning;
	_complaints[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{

	for (int i = 0; i < 4; i++)
	{
		if (level == _levels[i])
		{
			(this->*_complaints[i])();
			return;
		}
	}
	std::cerr << "Unknown complaint level: " << level << std::endl;
}

void Harl::debug()
{
	std::cout << COL_DEBUG MSG_DEBUG COL_RESET << std::endl;
}

void Harl::info()
{
	std::cout << COL_INFO MSG_INFO COL_RESET << std::endl;
}

void Harl::warning()
{
	std::cout << COL_WARNING MSG_WARNING COL_RESET << std::endl;
}

void Harl::error()
{
	std::cout << COL_ERROR MSG_ERROR COL_RESET << std::endl;
}
