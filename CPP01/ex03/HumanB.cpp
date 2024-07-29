/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:45:27 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 22:16:19 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (weapon != nullptr)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " can't attack because he has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
