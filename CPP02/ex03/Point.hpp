/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:26:21 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/28 16:06:48 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POINT_HPP
#define POINT_HPP

#include "iostream"
#include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point &copy);
		~Point(void);

		Point&	operator=(const Point &inst);

		bool bsp(Point const a, Point const b, Point const c, Point const point);
		
	private:
		Fixed const _x;
		Fixed const _y;
}

#endif