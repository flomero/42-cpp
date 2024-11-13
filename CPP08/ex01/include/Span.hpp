/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:31:47 by flfische          #+#    #+#             */
/*   Updated: 2024/11/12 19:50:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span
{
	private:
		Span() = delete;
		unsigned int _n;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span() = default;

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
};
