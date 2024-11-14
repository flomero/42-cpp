/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:45:25 by flfische          #+#    #+#             */
/*   Updated: 2024/11/14 15:02:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

#define DB_FILE "data.csv"
#define DB_HEADER "date,exchange_rate"
#define INPUT_HEADER "date | value"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define ERROR(x) std::cerr << RED << "ERROR: " << RESET << x << std::endl

class BitcoinExchange
{
	private:
		std::map<std::string, double> _btcRates;
		const std::string _dbFile = DB_FILE;
		std::string _inputFile;

		bool isValidDate(const std::string &date) const;
		bool isValidDBLine(const std::string &line) const;
		std::map<std::string, double>::const_iterator getRate(
			const std::string &date) const;
		bool isValidInput(const std::string &line) const;
		void printResult(const std::string &line) const;

	public:
		BitcoinExchange() = default;
		~BitcoinExchange() = default;

		void parseDatabase();
		void printDatabase();
		void handleInput(const std::string &inputFile);
};
