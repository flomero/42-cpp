/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:20 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 09:36:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_complaints["debug"] = &Harl::debug;
	_complaints["info"] = &Harl::info;
	_complaints["warning"] = &Harl::warning;
	_complaints["error"] = &Harl::error;
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
