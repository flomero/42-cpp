/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:51:08 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 15:17:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
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