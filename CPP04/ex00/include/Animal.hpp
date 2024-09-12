/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:56 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 15:48:37 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type = "Undefined Animal";

public:
	Animal() = default;
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal() = default;

	std::string getType() const;

	virtual void makeSound() const;
};
