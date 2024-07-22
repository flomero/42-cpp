/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:41:31 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 13:01:04 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class Phonebook
{
public:
	Contact contacts[8];
	int contact_count;

	Phonebook()
	{
		contact_count = 0;
	}
	void add_contact()
	{
		std::cout << "Enter first name: ";
		std::cin >> contacts[contact_count].first_name;
		std::cout << "Enter last name: ";
		std::cin >> contacts[contact_count].last_name;
		std::cout << "Enter nickname: ";
		std::cin >> contacts[contact_count].nickname;
		std::cout << "Enter phone number: ";
		std::cin >> contacts[contact_count].phone_number;
		std::cout << "Enter darkest secret: ";
		std::cin >> contacts[contact_count].darkest_secret;
		contact_count++;
		if (contact_count > 7)
			contact_count = 0;
	}
	void print_formatted_name(std::string name, std::string delim)
	{
		size_t i;
		if (name.length() > 10)
			std::cout << name.substr(0, 9) << ".";
		else
		{
			std::cout << name;
			for (i = 0; i < 10 - name.length(); i++)
				std::cout << " ";
		}
		std::cout << delim;
	}
	void search_contact()
	{
		int i;
		std::string index;
		std::cout << "index     |first name|last name |nickname  " << std::endl;
		for (i = 0; i < contact_count; i++)
		{
			std::cout << i << "         |";
			print_formatted_name(contacts[i].first_name, "|");
			print_formatted_name(contacts[i].last_name, "|");
			print_formatted_name(contacts[i].nickname, "\n");
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "Enter index: ";
			std::cin >> index;
			if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
			{
				i = index[0] - '0';
				std::cout << "first name:\t" << contacts[i].first_name << std::endl;
				std::cout << "last name:\t" << contacts[i].last_name << std::endl;
				std::cout << "nickname:\t" << contacts[i].nickname << std::endl;
				std::cout << "phone number:\t" << contacts[i].phone_number << std::endl;
				std::cout << "darkest secret:\t" << contacts[i].darkest_secret << std::endl;
				break;
			}
			else
				std::cout << "Invalid index" << std::endl;
		}
	}
};

#endif
