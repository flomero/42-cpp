/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:53 by flfische          #+#    #+#             */
/*   Updated: 2025/04/14 09:10:10 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PmergeMe.hpp"

int max_comp(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

bool isInteger(const std::string& str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	for (; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void checkinput(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (!isInteger(arg))
		{
			std::cerr << "Error: Argument " << arg << " is not an integer.\n";
			throw std::invalid_argument("");
		}
	}
}

void fill_vector(std::vector<int>& vec, int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		int num = std::stoi(arg);
		vec.push_back(num);
	}
}

void fill_deque(std::deque<int>& deq, int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		int num = std::stoi(arg);
		deq.push_back(num);
	}
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		os << vec[i];
		if (i < vec.size() - 1)
			os << " ";
	}
	return os;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: No integers provided as input.\n";
		std::cerr << "Usage: " << argv[0] << " <int1> <int2> ... <intN>\n";
		return 1;
	}
	std::vector<int> vec;
	std::deque<int> deq;

	try
	{
		checkinput(argc, argv);
	}
	catch (const std::exception& e)
	{
		return 1;
	}
	PmergeMe merge(DEBUG);
	clock_t start_vec;
	clock_t end_vec;
	clock_t start_deq;
	clock_t end_deq;

	std::cout << "Before:\t" << vec << std::endl;
	start_vec = clock();
	fill_vector(vec, argc, argv);
	merge.sort_vec(vec);
	end_vec = clock();
	for (size_t i = 0; i < vec.size() - 1; ++i)
	{
		if (vec[i] > vec[i + 1])
		{
			std::cerr << "Error: Vector is not sorted.\n";
			return 1;
		}
	}
	if (DEBUG)
	{
		std::cout << "max: " << std::to_string(max_comp(vec.size()))
				  << std::endl;
		std::cout << "comp: " << std::to_string(PmergeMe::comp_count)
				  << std::endl;
	}
	merge.resetCount();
	start_deq = clock();
	fill_deque(deq, argc, argv);
	merge.sort_deq(deq);
	end_deq = clock();
	for (size_t i = 0; i < deq.size() - 1; ++i)
	{
		if (deq[i] > deq[i + 1])
		{
			std::cerr << "Error: Vector is not sorted.\n";
			return 1;
		}
	}
	if (DEBUG)
	{
		std::cout << "max: " << std::to_string(max_comp(vec.size()))
				  << std::endl;
		std::cout << "comp: " << std::to_string(PmergeMe::comp_count)
				  << std::endl;
	}
	std::cout << "After:\t" << vec << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with "
			  << "std::vector<int>:\t"
			  << (double)(end_vec - start_vec) / CLOCKS_PER_SEC << " us"
			  << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with "
			  << "std::deque<int> :\t"
			  << (double)(end_deq - start_deq) / CLOCKS_PER_SEC << " us"
			  << std::endl;
	return 0;
}
