/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:30 by flfische          #+#    #+#             */
/*   Updated: 2025/04/10 19:57:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::sort_vec(std::vector<int> &vec)
{
	sort(vec);
}

void PmergeMe::sort_deq(std::deque<int> &deq)
{
	sort(deq);
}

void PmergeMe::debug(std::string str)
{
	if (_debug)
		std::cout << "DEBUG: " << str << std::endl;
}

int PmergeMe::comp_count = 0;
void PmergeMe::printCount()
{
	std::cout << "Number of comparisons: " << comp_count << std::endl;
}
