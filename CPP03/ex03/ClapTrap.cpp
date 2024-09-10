/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:38:46 by flfische          #+#    #+#             */
/*   Updated: 2024/08/08 15:31:28 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap")
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " is dead and cannot attack." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " is out of energy and cannot attack." << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " is already dead." << std::endl;
		return;
	}
	if (amount > _hitpoints)
		amount = _hitpoints;
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name
			  << " takes " << amount
			  << " points of damage!"
			  << " Remaining hitpoints: " << _hitpoints
			  << std::endl;
	if (_hitpoints == 0)
		std::cout << "ClapTrap " << _name
				  << " died." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " is dead and cannot be repaired." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " is out of energy and cannot take damage." << std::endl;
		return;
	}
	_energyPoints--;
	_hitpoints += amount;
	std::cout << "ClapTrap " << _name
			  << " is repaired for " << amount
			  << " hitpoints!"
			  << " Remaining hitpoints: " << _hitpoints
			  << std::endl;
}
