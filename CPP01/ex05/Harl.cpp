/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:20 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 10:37:27 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_complaints["DEBUG"] = &Harl::debug;
	_complaints["INFO"] = &Harl::info;
	_complaints["WARNING"] = &Harl::warning;
	_complaints["INFO"] = &Harl::error;
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
