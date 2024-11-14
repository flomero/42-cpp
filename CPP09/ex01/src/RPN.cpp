/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:52:15 by flfische          #+#    #+#             */
/*   Updated: 2024/11/14 17:11:37 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <regex>
#include <sstream>
#include <stack>

int RPN::calculate(const std::string& input)
{
	std::stack<int> stack;
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
			{
				ERROR("Too few operands");
				return 1;
			}
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(b + a);
			else if (token == "-")
				stack.push(b - a);
			else if (token == "*")
				stack.push(b * a);
			else if (token == "/")
			{
				if (a == 0)
				{
					ERROR("Division by zero");
					return 1;
				}
				stack.push(b / a);
			}
		}
		else
		{
			if (!std::regex_match(token, std::regex("^\\d$")))
			{
				ERROR("Invalid token: " + token);
				return 1;
			}
			stack.push(std::stoi(token));
		}
	}
	if (stack.size() != 1)
	{
		ERROR("Too few operators");
		return 1;
	}
	else
		std::cout << stack.top() << std::endl;
	return 0;
}