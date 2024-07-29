/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:45:33 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 22:15:17 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	void attack(void);
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
};