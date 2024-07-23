/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:36:38 by flfische          #+#    #+#             */
/*   Updated: 2024/07/23 11:15:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "colors.hpp"

bool Contact::set_first_name(const std::string first_name)
{
	if (first_name.empty())
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
	if (last_name.empty())
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
	if (nickname.empty())
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
	if (darkest_secret.empty())
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
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << INFO "Contact information:" RESET << std::endl;
	std::cout << SEMIBOLD "First name:\t\t" RESET << _first_name << std::endl;
	std::cout << SEMIBOLD "Last name:\t\t" RESET << _last_name << std::endl;
	std::cout << SEMIBOLD "Nickname:\t\t" RESET << _nickname << std::endl;
	std::cout << SEMIBOLD "Telephone number:\t" RESET << _phone_number << std::endl;
	std::cout << SEMIBOLD "Darkest secret:\t\t" RESET << _darkest_secret << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}
