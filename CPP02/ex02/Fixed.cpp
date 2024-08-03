/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:04 by flfische          #+#    #+#             */
/*   Updated: 2024/08/03 17:12:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _fixedPointValue(val << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _fixedPointValue(roundf(val * (1 << _fractionalBits)))
{

	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return *this;
	_fixedPointValue = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
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

bool Fixed::operator>(const Fixed &fixed)
{
	return _fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed)
{
	return _fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return _fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return _fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed)
{
	return _fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed)
{
	return _fixedPointValue != fixed.getRawBits();
}

Fixed &Fixed::operator+(const Fixed &fixed)
{
	_fixedPointValue += fixed.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(const Fixed &fixed)
{
	_fixedPointValue -= fixed.getRawBits();
	return *this;
}

Fixed &Fixed::operator*(const Fixed &fixed)
{
	_fixedPointValue = (_fixedPointValue * fixed.getRawBits()) >> _fractionalBits;
	return *this;
}

Fixed &Fixed::operator/(const Fixed &fixed)
{
	_fixedPointValue = (_fixedPointValue << _fractionalBits) / fixed.getRawBits();
	return *this;
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

Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
