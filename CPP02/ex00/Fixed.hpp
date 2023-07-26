/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:49 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/26 16:25:27 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		~Fixed(void);

		Fixed 	&operator=(const Fixed &test);
		int		getRawBits(void)const;
		void	setRawBits(int const raw);

	private:
		int					_nb;
		const static int	_bits = 8;
};

#endif