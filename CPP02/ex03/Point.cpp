/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:27:13 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 14:09:48 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void): _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	return ;
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

bool	Point::operator==(const Point& inst) const
{
	return ((this->_x == inst._x) && (this->_y == inst._y));
}

float	Point::find_area(Point const a, Point const b, Point const c)
{
	return (std::fabs((a._x.toFloat() * (b._y.toFloat() - c._y.toFloat()) + b._x.toFloat() * (c._y.toFloat() - a._y.toFloat()) + c._x.toFloat() * (a._y.toFloat() - b._y.toFloat())) / 2));
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area1 = find_area(a, b, point);
	float	area2 = find_area(a, point, c);
	float	area3 = find_area(point, b, c);;
	float	realarea = find_area(a, b, c);
	float	globalarea = area1 + area2 + area3;
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	return (realarea == globalarea);
}