/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:38:48 by flfische          #+#    #+#             */
/*   Updated: 2024/08/08 15:30:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2(claptrap);

	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(5);
	claptrap.takeDamage(5);
	claptrap2.attack("enemy");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	return 0;
}
