/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:00:55 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 09:52:05 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.h"

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	std::string getIdea(int index) const;
	void setIdea(int index, const std::string &idea);

private:
	static const int ideasCount = 100;
	std::string ideas[ideasCount];
};