/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:57:22 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 15:12:29 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created." << std::endl;
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignement operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitpoints <= 0)
	{
		std::cout << "FragTrap " << _name
				  << " is dead and cannot request a high five." << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_hitpoints == 0)
	{
		std::cout << "FragTrap " << _name
				  << " is dead and cannot attack." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name
				  << " has no energy and cannot attack." << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "FragTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
}
