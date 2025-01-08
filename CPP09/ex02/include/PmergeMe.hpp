/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:17 by flfische          #+#    #+#             */
/*   Updated: 2025/01/08 17:52:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <vector>

// 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &other) = default;
		PmergeMe &operator=(const PmergeMe &other) = default;

		template <typename T>
		void sort(T &container, int level = 1);

	public:
		PmergeMe() = default;
		~PmergeMe() = default;
		void sort_vec(std::vector<int> &vec);
		void sort_deq(std::deque<int> &deq);
};
