/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:17:17 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 11:14:12 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
	unsigned int _hitpoints = FragTrap::_hitpoints;
	unsigned int _energyPoints = ScavTrap::_energyPoints;
	unsigned int _attackDamage = FragTrap::_attackDamage;

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);

	void attack(const std::string &target) override;

	void whoAmI(void);
};
