/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:03:08 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 18:56:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating a Zombie horde:" << std::endl;
	std::cout << std::endl;
	Zombie *zombies = zombieHorde(5, "Zombie");
	std::cout << std::endl;
	std::cout << "Announcing the Zombie horde:" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	std::cout << std::endl;
	std::cout << "Deleting the Zombie horde:" << std::endl;
	std::cout << std::endl;
	delete[] zombies;
	return (0);
}
