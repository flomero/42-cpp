/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:07 by flfische          #+#    #+#             */
/*   Updated: 2024/08/03 17:05:16 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &fixed);

	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	// Comparison operators
	bool operator>(const Fixed &fixed);
	bool operator<(const Fixed &fixed);
	bool operator>=(const Fixed &fixed);
	bool operator<=(const Fixed &fixed);
	bool operator==(const Fixed &fixed);
	bool operator!=(const Fixed &fixed);

	// Arithmetic operators
	Fixed &operator+(const Fixed &fixed);
	Fixed &operator-(const Fixed &fixed);
	Fixed &operator*(const Fixed &fixed);
	Fixed &operator/(const Fixed &fixed);

	// Increment and decrement operators
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &, const Fixed &fixed);