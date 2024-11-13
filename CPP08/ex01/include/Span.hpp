/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:31:47 by flfische          #+#    #+#             */
/*   Updated: 2024/11/13 15:54:14 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
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
		template <typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _n)
				throw std::length_error("Span is too short");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int shortestSpan();
		int longestSpan();

		unsigned int size() const;
		std::vector<int> const &getNumbers() const;
};

std::ostream &operator<<(std::ostream &os, Span const &span);
