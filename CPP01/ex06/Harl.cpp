/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:20 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 10:28:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string filter) : _filter(filter), _filterLevel(-1)
{
	_complaints["DEBUG"] = &Harl::doNothing;
	_complaints["INFO"] = &Harl::doNothing;
	_complaints["WARNING"] = &Harl::doNothing;
	_complaints["ERROR"] = &Harl::doNothing;
	std::string filters[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (filter == filters[i])
			_filterLevel = i;
	}
	switch (_filterLevel)
	{
	case DEBUG:
		_complaints["DEBUG"] = &Harl::debug;
	case INFO:
		_complaints["INFO"] = &Harl::info;
	case WARNING:
		_complaints["WARNING"] = &Harl::warning;
	case ERROR:
		_complaints["ERROR"] = &Harl::error;
		break;
	default:
		std::cerr << "[ Probably complaining about insignificant problems ]" << filter << std::endl;
	}
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	void (Harl::*complaint)() = _complaints[level];
	if (complaint)
		(this->*complaint)();
	else
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

void Harl::doNothing()
{
}