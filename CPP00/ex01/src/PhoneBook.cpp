/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:59:10 by flfische          #+#    #+#             */
/*   Updated: 2024/07/23 11:15:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "colors.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
	index = 0;
}

void PhoneBook::check_input(const std::string &prompt, bool (Contact::*setter)(const std::string), Contact &contact)
{
	std::string input;
	std::cout << PROMPT << prompt << RESET;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	while ((contact.*setter)(input))
	{
		std::cout << WARNING "Invalid input. Please enter a valid input: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
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
	check_input("Enter first name: ", &Contact::set_first_name, contacts[index]);
	check_input("Enter last name: ", &Contact::set_last_name, contacts[index]);
	check_input("Enter nickname: ", &Contact::set_nickname, contacts[index]);
	check_input("Enter phone number: ", &Contact::set_phone_number, contacts[index]);
	check_input("Enter darkest secret: ", &Contact::set_darkest_secret, contacts[index]);
	std::cout << SUCCESS "Contact added successfully." RESET << std::endl;
	contact_count++;
	index++;
	if (index == 8)
		index = 0;
}

void PhoneBook::search_contact()
{
	size_t i;
	std::string input;
	if (contacts[0].get_first_name().empty())
	{
		std::cout << WARNING "No contacts available." << std::endl;
		return;
	}
	std::cout << BOLD "index     |first name|last name |nickname  " << std::endl;
	for (i = 0; i < 8; i++)
	{
		if (contacts[i].get_first_name().empty())
			break;
		std::cout << "-------------------------------------------" RESET << std::endl;
		std::cout << i << "         |";
		print_formatted_name(contacts[i].get_first_name(), "|");
		print_formatted_name(contacts[i].get_last_name(), "|");
		print_formatted_name(contacts[i].get_nickname(), "");
		std::cout << std::endl;
	}
	std::cout << PROMPT "Enter index of contact to view: " RESET;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	i = input[0] - '0';
	while (input.length() != 1 || input[0] < '0' || input[0] > '7' || i > 8 || contacts[i].get_first_name().empty())
	{
		std::cout << WARNING "Invalid index. Please try again: " RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		i = input[0] - '0';
	}
	contacts[i].print_contact();
}
