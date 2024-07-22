/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:59:10 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 13:23:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	Phonebook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return (0);
}
