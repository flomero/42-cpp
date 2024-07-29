/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:37:46 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 16:30:00 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "> destructed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
