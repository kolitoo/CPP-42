/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:49 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/31 10:50:20 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed
{
	public:
		
		/*constructeurs/destructeurs*/
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		/*Surcharge operateur assignation*/
		Fixed 	&operator=(const Fixed &test);

		/*Surcharge operateur comparaison*/
		bool	operator>(const Fixed& inst) const;
		bool	operator<(const Fixed& inst) const;
		bool	operator>=(const Fixed& inst) const;
		bool	operator<=(const Fixed& inst) const;
		bool	operator==(const Fixed& inst) const;
		bool	operator!=(const Fixed& inst) const;

		/*Surcharge operateur arithmetique*/
		Fixed	operator+(const Fixed &inst) const;
		Fixed	operator-(const Fixed &inst) const;
		Fixed	operator*(const Fixed &inst) const;
		Fixed	operator/(const Fixed &inst) const;

		/*Surcharge operateur incrementation*/
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		
		/*fonctions membres*/
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	 toFloat(void) const;
		int		toInt(void) const;
		static Fixed&		min(Fixed& first, Fixed& second);
		const static Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&		max(Fixed& first, Fixed& second);
		const static Fixed&	max(const Fixed& first, const Fixed& second);

	private:
		int					_nb;
		const static int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &in);

#endif