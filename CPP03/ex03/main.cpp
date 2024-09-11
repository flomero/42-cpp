/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:38:48 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 12:24:10 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap bob("Bob");

	bob.attack("Alice");
	bob.whoAmI();
	bob.guardGate();
	bob.takeDamage(10);
	bob.beRepaired(10);
	bob.takeDamage(100);

	return 0;
}
