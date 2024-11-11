/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:06:42 by flfische          #+#    #+#             */
/*   Updated: 2024/11/11 17:50:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (isChar(str))
		convertChar(str[0]);
	else if (isInt(str))
		convertInt(std::stoi(str));
	else if (isFloat(str))
		convertFloat(std::stof(str));
	else if (isDouble(str))
		convertDouble(std::stod(str));
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str)
{
	std::regex regex("^[-+]?[0-9]+$");
	if (!std::regex_match(str, regex))
		return false;
	try
	{
		std::stoi(str);
	}
	catch (const std::out_of_range &e)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &str)
{
	std::regex regex(
		"^[-+]?[0-9]+\\.[0-9]+[fF]$|^[-+]?[0-9]+[fF]$|^(\\+inff|-inff|nanf)$");
	if (!std::regex_match(str, regex))
		return false;
	try
	{
		std::stof(str);
	}
	catch (const std::out_of_range &e)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &str)
{
	std::regex regex("^[-+]?[0-9]+\\.[0-9]+$|^(\\+inf|-inf|nan)$");
	if (!std::regex_match(str, regex))
		return false;
	try
	{
		std::stod(str);
	}
	catch (const std::out_of_range &e)
	{
		return false;
	}
	return true;
}

void ScalarConverter::convertChar(const char &c)
{
	if (DEBUG)
		std::cout << CYAN << "Converting Char" << RESET << std::endl;
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const int &i)
{
	if (DEBUG)
		std::cout << CYAN << "Converting Int" << RESET << std::endl;
	if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const float &f)
{
	if (DEBUG)
		std::cout << CYAN << "Converting Float" << RESET << std::endl;

	if (std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(f))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	if (std::isnan(f) || std::isinf(f) || f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (f - static_cast<int>(f) == 0 && f < INT_MAX && f > INT_MIN)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (f - static_cast<int>(f) == 0)
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const double &d)
{
	if (DEBUG)
		std::cout << CYAN << "Converting Double" << RESET << std::endl;

	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(d))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (d > std::numeric_limits<float>::max() ||
		d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else if (d - static_cast<int>(d) == 0 && d < INT_MAX && d > INT_MIN)
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
