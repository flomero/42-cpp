/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:20:03 by flfische          #+#    #+#             */
/*   Updated: 2024/08/04 12:30:00 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(Point const &other);
	Point(float const x, float const y);
	~Point();

	Point &operator=(Point const &other);

	Fixed const getX() const;
	Fixed const getY() const;

private:
	Fixed const x;
	Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
