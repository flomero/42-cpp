/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:07:43 by flfische          #+#    #+#             */
/*   Updated: 2024/08/01 13:59:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string str1, std::string str2) : _filename(filename), _str1(str1), _str2(str2)
{
}

Replace::~Replace()
{
}

void Replace::replace()
{
	if (_str1.empty())
	{
		std::cerr << "Error: Can't replace empty string." << std::endl;
		return;
	}
	std::ifstream file(_filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: File can't be opened." << std::endl;
		return;
	}
	std::ofstream output((_filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cerr << "Error: Could not create output file" << std::endl;
		return;
	}
	std::string line;
	std::string modifiedLine;
	while (std::getline(file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(_str1, pos)) != std::string::npos)
		{
			modifiedLine += line.substr(0, pos) + _str2;
			line = line.substr(pos + _str1.length());
			pos = 0;
		}
		modifiedLine += line;
		output << modifiedLine << std::endl;
		modifiedLine.clear();
	}
	file.close();
}
