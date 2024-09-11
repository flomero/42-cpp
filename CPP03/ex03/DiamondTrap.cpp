/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:17:15 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 13:45:22 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap " << name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.ClapTrap::_name), ScavTrap(other.ScavTrap::_name), FragTrap(other.FragTrap::_name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	ClapTrap::_name = other.ClapTrap::_name;
	_hitpoints = other._hitpoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
