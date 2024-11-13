/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:03:22 by flfische          #+#    #+#             */
/*   Updated: 2024/11/13 15:54:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &other) : _n(other._n), _numbers(other._numbers) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _n)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw std::length_error("Span is too short");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int shortest = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw std::length_error("Span is too short");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

unsigned int Span::size() const
{
	return _numbers.size();
}

std::vector<int> const &Span::getNumbers() const
{
	return _numbers;
}

std::ostream &operator<<(std::ostream &os, Span const &span)
{
	os << "Span(" << span.size() << "): {";
	std::vector<int> const &numbers = span.getNumbers();
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (i > 0)
			os << ", ";
		os << numbers[i];
	}
	os << "}";
	return os;
}