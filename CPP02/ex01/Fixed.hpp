/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:49 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/26 16:52:01 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		Fixed 	&operator=(const Fixed &test);
		
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	 toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_nb;
		const static int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &in);

#endif