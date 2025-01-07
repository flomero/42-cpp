/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:17 by flfische          #+#    #+#             */
/*   Updated: 2025/01/07 14:29:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &other) = default;
		PmergeMe &operator=(const PmergeMe &other) = default;

		template <typename T>
		void sort(T &container);

	public:
		PmergeMe() = default;
		~PmergeMe() = default;
		void sort_vec(std::vector<int> &vec);
		void sort_deq(std::deque<int> &deq);
};
