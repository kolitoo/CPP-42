/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:26:21 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/31 11:31:22 by abourdon         ###   ########.fr       */
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
		bool	operator==(const Point& inst) const;
		bool bsp(Point const a, Point const b, Point const c, Point const point);
		float	find_area(Point const a, Point const b, Point const c);

	private:
		Fixed _x;
		Fixed _y;
};

#endif