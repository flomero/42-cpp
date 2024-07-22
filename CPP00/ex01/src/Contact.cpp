/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:36:38 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 15:08:59 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
	std::cout << "First name:\t" << _first_name << std::endl;
	std::cout << "Last name:\t" << _last_name << std::endl;
	std::cout << "Nickname:\t" << _nickname << std::endl;
	std::cout << "Telephone number:\t" << _phone_number << std::endl;
	std::cout << "Darkest secret:\t" << _darkest_secret << std::endl;
}
