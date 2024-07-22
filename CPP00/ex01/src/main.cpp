/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:51:08 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 16:10:39 by flfische         ###   ########.fr       */
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
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return (0);
}