/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:52:21 by flfische          #+#    #+#             */
/*   Updated: 2024/11/14 17:08:03 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"
#define ERROR(x) std::cerr << RED << "ERROR: " << RESET << x << std::endl

class RPN
{
	public:
		static int calculate(const std::string &input);

	private:
		RPN() = delete;
		RPN(const RPN &other) = delete;
		RPN &operator=(const RPN &other) = delete;
		~RPN() = default;
};