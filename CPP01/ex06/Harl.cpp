/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:20 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 13:58:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string filter) : _filter(filter), _filterLevel(-1)
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_complaints[0] = NULL;
	_complaints[1] = NULL;
	_complaints[2] = NULL;
	_complaints[3] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (filter == _levels[i])
			_filterLevel = i;
	}
	switch (_filterLevel)
	{
	case DEBUG:
		_complaints[DEBUG] = &Harl::debug;
	case INFO:
		_complaints[INFO] = &Harl::info;
	case WARNING:
		_complaints[WARNING] = &Harl::warning;
	case ERROR:
		_complaints[ERROR] = &Harl::error;
		break;
	default:
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
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
			if (_complaints[i] != NULL)
				(this->*_complaints[i])();
			return;
		}
	}
	std::cerr << "Unknown complaint level: " << level << std::endl;
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << COL_DEBUG MSG_DEBUG COL_RESET << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << COL_INFO MSG_INFO COL_RESET << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << COL_WARNING MSG_WARNING COL_RESET << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << COL_ERROR MSG_ERROR COL_RESET << std::endl;
}
