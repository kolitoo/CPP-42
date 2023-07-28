/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:27:13 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/28 16:06:42 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
	return ;
}

Point::Point(float x, float y): _x(x), _y(y)
{
	return ;
}

Point::Point(const Point &copy)
{
	*this = copy;
	return ;
}

Point::~Point(void)
{
	return ;
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	
}