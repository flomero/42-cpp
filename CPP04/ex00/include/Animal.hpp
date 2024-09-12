/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:56 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 09:43:04 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RESET "\033[0m"
// light blue and italic light
#define LOG "\033[3;96m"

class Animal
{
protected:
	std::string type = "Undefined Animal";

public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	std::string getType() const;

	virtual void makeSound() const;
};
