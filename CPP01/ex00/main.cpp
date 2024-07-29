/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:03:08 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 16:23:22 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating a Zombie on the heap:" << std::endl;
	std::cout << std::endl;
	Zombie *zombie = newZombie("Zombie");
	zombie->announce();
	std::cout << std::endl;
	std::cout << "Deleting the Zombie on the heap:" << std::endl;
	std::cout << std::endl;
	delete zombie;
	std::cout << std::endl;
	std::cout << "Creating a Zombie on the stack:" << std::endl;
	std::cout << std::endl;
	randomChump("Chump");
	return (0);
}
