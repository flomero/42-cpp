/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:17:15 by flfische          #+#    #+#             */
/*   Updated: 2024/09/10 17:49:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	_name = "Default";
	ClapTrap::_name = _name + "_clap_name";
	_hitpoints = FragTrap::_hitpoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitpoints = FragTrap::_hitpoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
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

// DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), ScavTrap(), FragTrap()
// {
// 	_name = other._name;
// 	ClapTrap::_name = other.ClapTrap::_name;
// 	_hitpoints = other._hitpoints;
// 	_energyPoints = other._energyPoints;
// 	_attackDamage = other._attackDamage;
// 	std::cout << "DiamondTrap copy constructor called" << std::endl;
// }

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
