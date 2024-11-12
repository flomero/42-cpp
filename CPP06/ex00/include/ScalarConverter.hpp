/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:07:12 by flfische          #+#    #+#             */
/*   Updated: 2024/11/12 09:52:22 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>
#include <regex>

#ifndef DEBUG
#define DEBUG 0
#endif

#define CYAN "\033[0;36m"
#define RESET "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
		~ScalarConverter() = delete;

		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);

		static void convertChar(const char &c);
		static void convertInt(const int &i);
		static void convertFloat(const float &f);
		static void convertDouble(const double &d);

	public:
		static void convert(const std::string &str);
};
