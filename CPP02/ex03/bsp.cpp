/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:20:00 by flfische          #+#    #+#             */
/*   Updated: 2024/09/10 13:08:48 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

Fixed computeDeterminant(Point const &p1, Point const &p2, Point const &p)
{
	return (p1.getY() - p2.getY()) * (p.getX() - p2.getX()) + (p2.getX() - p1.getX()) * (p.getY() - p2.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed denom = computeDeterminant(b, c, a);
	Fixed x = computeDeterminant(b, c, point) / denom;
	Fixed y = computeDeterminant(c, a, point) / denom;
	Fixed z = Fixed(1.0f) - x - y;

	return (x > Fixed(0.0f) && y > Fixed(0.0f) && z > Fixed(0.0f));
}
