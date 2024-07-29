/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:41:16 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 21:42:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	void attack(void);
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
};
