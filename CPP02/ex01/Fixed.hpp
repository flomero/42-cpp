/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:07 by flfische          #+#    #+#             */
/*   Updated: 2024/08/03 13:15:33 by flfische         ###   ########.fr       */
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
};

std::ostream &operator<<(std::ostream &, const Fixed &fixed);