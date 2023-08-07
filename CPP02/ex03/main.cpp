/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:30 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 14:14:41 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point a(1, 1);
	Point b(2, 2);
	Point c(3, 0);
	// Point point(2.46, 1.08);//arrete
	// Point point(2, 1);//dans triangle
	Point point(2, -1);//exterieur triangle

	if (point.bsp(a, b, c, point) == true)
		std::cout << "Point dans triangle" << std::endl;
	else
		std::cout << "Point exterieur triangle" << std::endl;
	return (0);
}