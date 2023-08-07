/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:45 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 13:44:58 by abourdon         ###   ########.fr       */
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
/*Constructeur qui convertie un int value en virgule fixe.*/
Fixed::Fixed(const int value)
{
	this->_nb = value << _bits;
	std::cout << "Int constructor called" << std::endl;
	return ;
}
/*Constructeur qui converti un float value en virgule fixe.*/
Fixed::Fixed(const float value)
{
	this->_nb = roundf(value * (1 << _bits));
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
	std::cout <<"setRawBits member function called" << std::endl;
	return ;
}
/*divise _nb par 2 eleve a la puissance du nombre de bits de la partie
fractionnaire. Converti en float*/
float Fixed::toFloat(void) const
{
	return ((float)(this->_nb) / (1 << this->_bits));
}

/*decale la valeur en virgule fixe de bits positions vers la droite, laisse
seulement les bits de la partie entiere*/
int	Fixed::toInt(void)const
{
	return ((int)(this->_nb >> this->_bits));
}

Fixed	&Fixed::operator=(const Fixed &test)
{
	if (this != &test)
		std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = test.getRawBits();
	return (*this);
}

/*Prend un objet Fixed en entree et convertit sa valeur en float et envoie au flux de sortie specifie.*/
std::ostream &operator<<(std::ostream &out, Fixed const &in)
{
	out << in.toFloat();
	return (out);
}