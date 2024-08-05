/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:20:05 by flfische          #+#    #+#             */
/*   Updated: 2024/08/05 12:36:57 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Point const &other) : x(other.x), y(other.y)
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Point::~Point()
{
}

Point &Point::operator=(Point const &other)
{
	static_cast<void>(other);
	return *this;
}

Fixed const Point::getX() const
{
	return x;
}

Fixed const Point::getY() const
{
	return y;
}