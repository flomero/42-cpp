/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:45:25 by flfische          #+#    #+#             */
/*   Updated: 2024/11/14 14:05:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

#define DB_FILE "data.csv"
#define DB_HEADER "date,exchange_rate"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _btcRates;
		const std::string _dbFile = DB_FILE;
		std::string _inputFile;

		bool isValidDate(const std::string &date);
		bool isValidDBLine(const std::string &line);

	public:
		BitcoinExchange() = default;
		~BitcoinExchange() = default;

		void parseDatabase();
		void printDatabase();
};
