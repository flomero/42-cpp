/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:51:08 by flfische          #+#    #+#             */
/*   Updated: 2024/07/23 11:11:14 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "colors.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	std::cout << INFO "Available commands: ADD, SEARCH, EXIT" RESET << std::endl;
	while (1)
	{
		std::cout << PROMPT "Enter a command: " RESET;
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else
			std::cout << ERROR "Invalid command. Please enter ADD, SEARCH, or EXIT." RESET << std::endl;
	}
	return (0);
}