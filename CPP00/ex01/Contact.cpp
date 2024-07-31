/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:36:38 by flfische          #+#    #+#             */
/*   Updated: 2024/07/31 15:55:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "colors.h"

bool is_alpha(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isalpha(str[i]))
			return false;
	return true;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool Contact::set_first_name(const std::string first_name)
{
	if (first_name.empty() || !is_alpha(first_name))
		return true;
	_first_name = first_name;
	return false;
}

std::string Contact::get_first_name()
{
	return _first_name;
}

bool Contact::set_last_name(const std::string last_name)
{
	if (last_name.empty() || !is_alpha(last_name))
		return true;
	_last_name = last_name;
	return false;
}

std::string Contact::get_last_name()
{
	return _last_name;
}

bool Contact::set_nickname(const std::string nickname)
{
	if (nickname.empty() || !is_alpha(nickname))
		return true;
	_nickname = nickname;
	return false;
}

std::string Contact::get_nickname()
{
	return _nickname;
}

bool Contact::set_phone_number(const std::string phone_number)
{
	if (phone_number.empty())
		return true;
	int i = 0;
	if (phone_number[0] == '+')
		i++;
	while (phone_number[i])
	{
		if (!std::isdigit(phone_number[i]))
			return true;
		i++;
	}
	_phone_number = phone_number;
	return false;
}

std::string Contact::get_phone_number()
{
	return _phone_number;
}

bool Contact::set_darkest_secret(const std::string darkest_secret)
{
	if (darkest_secret.empty() || !is_alpha(darkest_secret))
		return true;
	_darkest_secret = darkest_secret;
	return false;
}

std::string Contact::get_darkest_secret()
{
	return _darkest_secret;
}

void Contact::print_contact()
{
	std::cout << "-------------------------------------------" << "\n"
			  << INFO "Contact information:" RESET << "\n"
			  << SEMIBOLD "First name:\t\t" RESET << _first_name << "\n"
			  << SEMIBOLD "Last name:\t\t" RESET << _last_name << "\n"
			  << SEMIBOLD "Nickname:\t\t" RESET << _nickname << "\n"
			  << SEMIBOLD "Telephone number:\t" RESET << _phone_number << "\n"
			  << SEMIBOLD "Darkest secret:\t\t" RESET << _darkest_secret << "\n"
			  << "-------------------------------------------" << std::endl;
}
