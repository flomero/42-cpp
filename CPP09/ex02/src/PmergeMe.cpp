/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:30 by flfische          #+#    #+#             */
/*   Updated: 2025/01/07 14:11:33 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.tpp"

void PmergeMe::sort_vec(std::vector<int> &vec)
{
	sort(vec);
}

void PmergeMe::sort_deq(std::deque<int> &deq)
{
	sort(deq);
}