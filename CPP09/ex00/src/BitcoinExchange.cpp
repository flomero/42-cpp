/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:45:40 by flfische          #+#    #+#             */
/*   Updated: 2024/11/14 15:03:58 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <array>
#include <fstream>
#include <iostream>
#include <regex>

void BitcoinExchange::parseDatabase()
{
	std::ifstream file(_dbFile);
	if (!file.is_open())
		throw std::runtime_error("Could not open file");

	std::string line;
	std::getline(file, line);
	if (line != DB_HEADER)
	{
		file.close();
		throw std::runtime_error("Invalid header in database");
	}

	int i = 1;
	while (std::getline(file, line))
	{
		if (!isValidDBLine(line))
		{
			file.close();
			throw std::runtime_error("Invalid line in database: Line " +
									 std::to_string(i));
		}
		i++;
		std::string date = line.substr(0, 10);
		double rate = std::stod(line.substr(11));
		_btcRates[date] = rate;
	}
	file.close();
	if (_btcRates.empty())
		throw std::runtime_error("No valid data in database");
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	static const std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30,
													31, 31, 30, 31, 30, 31};

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (month < 1 || month > 12 || day < 1)
		return false;

	int maxDays = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDays = 29;

	return day <= maxDays;
}

bool BitcoinExchange::isValidDBLine(const std::string &line) const
{
	std::regex pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2},[0-9]+(\\.[0-9]+)?$");
	if (!std::regex_match(line, pattern))
		return false;
	if (!isValidDate(line.substr(0, 10)))
		return false;
	return true;
}

void BitcoinExchange::printDatabase()
{
	for (const auto &rate : _btcRates)
		std::cout << rate.first << " " << rate.second << std::endl;
}

std::map<std::string, double>::const_iterator BitcoinExchange::getRate(
	const std::string &date) const
{
	auto it = _btcRates.find(date);
	if (it != _btcRates.end())
		return it;
	// find closest previous date
	for (auto it = _btcRates.rbegin(); it != _btcRates.rend(); it++)
	{
		if (it->first < date)
			return std::next(it).base();
	}
	return _btcRates.end();
}

void BitcoinExchange::handleInput(const std::string &inputFile)
{
	std::ifstream file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Could not open file");

	std::string line;
	std::getline(file, line);
	if (line != INPUT_HEADER)
	{
		file.close();
		throw std::runtime_error("Invalid input file");
	}
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		printResult(line);
	}
	file.close();
}

bool BitcoinExchange::isValidInput(const std::string &line) const
{
	std::regex pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| [0-9]+(\\.[0-9]+)?$");
	if (!std::regex_match(line, pattern))
	{
		ERROR("Invalid format: " + line);
		return false;
	}
	if (!isValidDate(line))
	{
		ERROR("Invalid date: " + line.substr(0, 10));
		return false;
	}
	if (std::stod(line.substr(13)) < 0 || std::stod(line.substr(13)) > 1000)
	{
		ERROR("Invalid rate: " + line.substr(13));
		return false;
	}
	return true;
}

void BitcoinExchange::printResult(const std::string &line) const
{
	if (!isValidInput(line))
		return;

	std::string date = line.substr(0, 10);
	double val = std::stod(line.substr(13));
	auto it = getRate(date);
	if (it == _btcRates.end())
	{
		ERROR("Date before first entry: " + date);
		return;
	}
	if (it->first != date)
	{
		std::cout << YELLOW << "WARNING: " << RESET << "No matching rate for "
				  << date << ", using " << it->first << std::endl;
		std::cout << date << " => " << val << " = " << val * it->second
				  << std::endl;
	}
	else
		std::cout << date << " => " << val << " = " << val * it->second
				  << std::endl;
}