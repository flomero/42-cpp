/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:17 by flfische          #+#    #+#             */
/*   Updated: 2025/04/10 20:21:19 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe() = default;
		PmergeMe(bool debug) : _debug(debug) {}
		~PmergeMe() = default;

		void sort_vec(std::vector<int> &vec);
		void sort_deq(std::deque<int> &deq);
		void printCount();

	private:
		bool _debug = true;
		void debug(std::string str);

		PmergeMe(const PmergeMe &src) = default;
		PmergeMe &operator=(const PmergeMe &src) = default;

		static int comp_count;
		template <typename T>
		bool comp(T a, T b);

		template <typename T>
		void swap_pair(T it, int level);

		template <typename T>
		void sort(T &container, int level = 1);
};

template <typename T>
bool PmergeMe::comp(T a, T b)
{
	comp_count++;
	return *a > *b;
}

template <typename T>
void PmergeMe::swap_pair(T pairOneBiggest, int level)
{
	T p1 = std::next(pairOneBiggest, -level + 1);
	T p2 = std::next(pairOneBiggest, 1);
	for (int i = 0; i < level; ++i)
	{
		std::iter_swap(p1, p2);
		p1 = std::next(p1, 1);
		p2 = std::next(p2, 1);
	}
}

template <typename T>
void PmergeMe::sort(T &container, int level)
{
	typedef typename T::iterator I;
	int pairs = container.size() / (level * 2);
	if (pairs == 0)
		return;
	I it = container.begin();
	I start = std::next(it, level - 1);
	I end = std::next(it, level * 2 - 1);

	for (int i = 0; i < pairs; ++i)
	{
		if (comp(start, end))
			swap_pair(start, level);
		start = std::next(start, level * 2);
		end = std::next(end, level * 2);
	}
	// print the container
	debug("Container after swapping pairs: " + std::to_string(level));
	for (I it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	sort(container, level * 2);
}