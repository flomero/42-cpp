/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:20 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 17:52:49 by flfische         ###   ########.fr       */
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
		// intentional fallthrough
	case INFO:
		_complaints[INFO] = &Harl::info;
		// intentional fallthrough
	case WARNING:
		_complaints[WARNING] = &Harl::warning;
		// intentional fallthrough
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
	std::cout << "[ DEBUG ]\n"
			  << COL_DEBUG MSG_DEBUG COL_RESET << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n"
			  << COL_INFO MSG_INFO COL_RESET << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n"
			  << COL_WARNING MSG_WARNING COL_RESET << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n"
			  << COL_ERROR MSG_ERROR COL_RESET << std::endl;
}
