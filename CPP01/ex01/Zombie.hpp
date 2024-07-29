/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:34:59 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 18:38:05 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);
