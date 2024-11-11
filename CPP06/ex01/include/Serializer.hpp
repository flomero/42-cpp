/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:52:59 by flfische          #+#    #+#             */
/*   Updated: 2024/11/11 19:57:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"

class Serializer
{
	private:
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(const Serializer &src) = delete;
		Serializer &operator=(const Serializer &src) = delete;

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
