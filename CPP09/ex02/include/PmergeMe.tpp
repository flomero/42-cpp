/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:55:14 by flfische          #+#    #+#             */
/*   Updated: 2025/01/08 18:08:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>

#include "PmergeMe.hpp"

int next_jacobsthal(int n)
{
	int numbers[11] = {
		3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731,
	};

	for (int i = 0; i < 11; i++)
	{
		if (numbers[i] > n)
			return numbers[i];
	}
}

template <typename T>
void swap_pair(T it, int level)
{
	T start = std::next(it, level - 1);
	T end = std::next(it, level * 2 - 1);
	if (*start > *end)
	{
		std::cout << "Swapping: " << *start << " and " << *end << std::endl;
		start = it;
		end = std::next(it, level);
		for (int i = 0; i < level; i++)
		{
			std::iter_swap(start, end);
			start++;
			end++;
		}
	}
}

template <typename T>
void PmergeMe::sort(T &container, int level)
{
	typedef typename T::iterator I;
	int pairs = container.size() / level;
	if (pairs < 2)
		return;
	for (int i = 0; i < pairs; i = i + 2)
	{
		I it = std::next(container.begin(), i * level);
		if (std::distance(it, container.end()) >= level * 2)
		{
			swap_pair(it, level);
		}
	}
	std::cout << "Level" << level << ": ";
	for (auto &elem : container) std::cout << elem << " ";
	std::cout << std::endl;
	sort(container, level * 2);
}