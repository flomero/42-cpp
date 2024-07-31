/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:19:34 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 19:03:24 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define COL_RESET "\033[0m"
#define COL_DEBUG "\033[1;34m"
#define COL_INFO "\033[1;32m"
#define COL_WARNING "\033[1;33m"
#define COL_ERROR "\033[1;31m"

#define MSG_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !"
#define MSG_INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define MSG_WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define MSG_ERROR "This is unacceptable! I want to speak to the manager now."

class Harl
{
public:
	Harl();
	Harl(std::string fiter);
	~Harl();
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
	std::string _levels[4];
	void (Harl::*_complaints[4])();
	std::string _filter;
	int _filterLevel;
	enum filterLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};
};
