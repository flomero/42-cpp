/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:17 by flfische          #+#    #+#             */
/*   Updated: 2025/04/10 19:58:51 by flfische         ###   ########.fr       */
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
void PmergeMe::swap_pair(T it, int level)
{
}

template <typename T>
void PmergeMe::sort(T &container, int level)
{
}