/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:29:04 by flfische          #+#    #+#             */
/*   Updated: 2024/09/11 15:43:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other) = default;
	Cat &operator=(const Cat &other) = default;
	~Cat() = default;

	void makeSound() const override;
};