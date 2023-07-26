/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:45 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/26 16:28:29 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_nb = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
	std::cout <<"setRawBits member function called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &test)
{
	if (this != &test)
		std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = test.getRawBits();
	return (*this);
}