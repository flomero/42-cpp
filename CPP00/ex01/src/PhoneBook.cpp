/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:59:10 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 15:23:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
}

void PhoneBook::check_input(const std::string &prompt, bool (Contact::*setter)(const std::string), Contact &contact)
{
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	while ((contact.*setter)(input))
	{
		std::cout << "Invalid input. Please enter a valid input: ";
		std::getline(std::cin, input);
	}
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

void PhoneBook::add_contact()
{
	check_input("Enter first name: ", &Contact::set_first_name, contacts[contact_count]);
	check_input("Enter last name: ", &Contact::set_last_name, contacts[contact_count]);
	check_input("Enter nickname: ", &Contact::set_nickname, contacts[contact_count]);
	check_input("Enter phone number: ", &Contact::set_phone_number, contacts[contact_count]);
	check_input("Enter darkest secret: ", &Contact::set_darkest_secret, contacts[contact_count]);
	contact_count++;
	if (contact_count == 8)
		contact_count = 0;
}

void PhoneBook::search_contact()
{
	size_t i;
	std::string input;
	std::cout << "index     |first name|last name |nickname  " << std::endl;
	for (i = 0; i < contact_count; i++)
	{
		std::cout << i << "         |";
		print_formatted_name(contacts[i].get_first_name(), "|");
		print_formatted_name(contacts[i].get_last_name(), "|");
		print_formatted_name(contacts[i].get_nickname(), "");
		std::cout << std::endl;
	}
	std::cout << "Enter index of contact to view: ";
	std::cin >> input;
	while (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid input. Please enter a valid input: ";
		std::cin >> input;
	}
	i = input[0] - '0';
	if (i >= contact_count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	contacts[i].print_contact();
}
