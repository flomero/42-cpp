/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:04 by flfische          #+#    #+#             */
/*   Updated: 2024/09/10 14:37:31 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	if (PRINT)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _fixedPointValue(val << _fractionalBits)
{
	if (PRINT)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _fixedPointValue(roundf(val * (1 << _fractionalBits)))
{
	if (PRINT)
		std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	if (PRINT)
		std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	if (PRINT)
		std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (PRINT)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return *this;
	_fixedPointValue = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	if (PRINT)
		std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	if (PRINT)
		std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedPointValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return _fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return _fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return _fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return _fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return _fixedPointValue != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits((_fixedPointValue * fixed.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed result;

	if (fixed.getRawBits() == 0)
		throw std::invalid_argument("Error: Division by zero");
	result.setRawBits((_fixedPointValue << _fractionalBits) / fixed.getRawBits());
	return result;
}

Fixed &Fixed::operator++()
{
	_fixedPointValue++;
	return *this;
}

Fixed &Fixed::operator--()
{
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
