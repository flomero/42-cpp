/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:53:31 by flfische          #+#    #+#             */
/*   Updated: 2024/11/11 20:14:34 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data data;
	data.s1 = "Hello";
	data.s2 = "World";
	data.n = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	std::cout << "n: " << ptr->n << std::endl;

	return 0;
}
