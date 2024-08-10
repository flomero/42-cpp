/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:38:48 by flfische          #+#    #+#             */
/*   Updated: 2024/08/10 14:50:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavTrap("Tim");
	ScavTrap scavTrap2(scavTrap);

	scavTrap.attack("enemy");
	scavTrap2.attack("enemy");
	scavTrap.guardGate();
	scavTrap2.guardGate();
	return 0;
}
