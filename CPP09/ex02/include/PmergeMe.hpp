/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:17 by flfische          #+#    #+#             */
/*   Updated: 2025/04/13 18:55:37 by flfische         ###   ########.fr       */
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
struct container_of
{
		typedef std::vector<T> type;
};

template <typename V>
struct container_of<std::deque<V>>
{
		typedef std::deque<std::deque<V>> type;
};

template <typename V>
struct container_of<std::vector<V>>
{
		typedef std::vector<std::vector<V>> type;
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
	// debug("Container after swapping pairs: " + std::to_string(level));
	// for (I it = container.begin(); it != container.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	sort(container, level * 2);

	typename container_of<T>::type main_groups;
	typename container_of<T>::type pending_groups;
	T leftover;

	T first_main_group;
	first_main_group.insert(first_main_group.end(), container.begin(),
							std::next(container.begin(), level));
	main_groups.push_back(first_main_group);

	T first_pend_group;
	first_pend_group.insert(first_pend_group.end(),
							std::next(container.begin(), level),
							std::next(container.begin(), level * 2));
	main_groups.push_back(first_pend_group);

	for (int i = level * 2; i < 2 * level * pairs; i += level * 2)
	{
		T pending_group;
		pending_group.insert(pending_group.end(),
							 std::next(container.begin(), i),
							 std::next(container.begin(), i + level));
		pending_groups.push_back(pending_group);

		if (i + level < 2 * level * pairs)
		{
			T main_group;
			main_group.insert(main_group.end(),
							  std::next(container.begin(), i + level),
							  std::next(container.begin(), i + level * 2));
			main_groups.push_back(main_group);
		}
	}

	int check = container.size() % (level * 2);
	if (check)
	{
		if (check > level)
		{
			T pending_group;
			pending_group.insert(
				pending_group.end(),
				std::next(container.begin(), 2 * level * pairs),
				std::next(container.begin(), 2 * level * pairs + level));
			pending_groups.push_back(pending_group);
		}

		if (check - level > 0)
			leftover.insert(
				leftover.end(),
				std::next(container.begin(), 2 * level * pairs + level),
				container.end());
		else
			leftover.insert(leftover.end(),
							std::next(container.begin(), 2 * level * pairs),
							container.end());
	}

	// Debug output for groups
	debug("Main groups: " + std::to_string(level));
	for (auto &group : main_groups)
	{
		std::cout << "[ ";
		for (auto it = group.begin(); it != group.end(); ++it)
			std::cout << *it << " ";
		std::cout << "] ";
	}
	std::cout << std::endl;

	debug("Pending groups: " + std::to_string(level));
	for (auto &group : pending_groups)
	{
		std::cout << "[ ";
		for (auto it = group.begin(); it != group.end(); ++it)
			std::cout << *it << " ";
		std::cout << "] ";
	}
	std::cout << std::endl;

	debug("Leftover: " + std::to_string(level));
	for (auto it = leftover.begin(); it != leftover.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}