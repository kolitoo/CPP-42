/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:26:21 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 14:02:39 by abourdon         ###   ########.fr       */
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
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point(void);

		bool	operator==(const Point& inst) const;
		bool bsp(Point const a, Point const b, Point const c, Point const point);
		float	find_area(Point const a, Point const b, Point const c);

	private:
		const Fixed _x;
		const Fixed _y;
		Point&	operator=(const Point &inst);
};

#endif