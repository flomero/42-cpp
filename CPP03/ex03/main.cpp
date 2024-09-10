/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:38:48 by flfische          #+#    #+#             */
/*   Updated: 2024/08/10 17:02:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap scavTrap("ScavTrap");
	FragTrap fragTrap("FragTrap");

	scavTrap.attack("FragTrap");
	fragTrap.attack("ScavTrap");

	scavTrap.guardGate();
	fragTrap.highFivesGuys();

	return 0;
}
