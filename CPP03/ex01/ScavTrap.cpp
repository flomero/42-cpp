/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:34:26 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 15:09:48 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " created." << std::endl;
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitpoints == 0)
	{
		std::cout << "ScavTrap " << _name
				  << " is dead and cannot attack." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name
				  << " has no energy and cannot attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name
			  << " attacks " << target
			  << " causing " << _attackDamage
			  << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	if (_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << _name
				  << " is dead and cannot do anything." << std::endl;
		return;
	}
	if (_inGuardMode)
	{
		std::cout << "ScavTrap " << _name << " is already in Gate keeper mode." << std::endl;
		return;
	}
	_inGuardMode = true;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
