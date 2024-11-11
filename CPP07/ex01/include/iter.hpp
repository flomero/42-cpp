/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:55:06 by flfische          #+#    #+#             */
/*   Updated: 2024/11/11 21:56:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

template <typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
