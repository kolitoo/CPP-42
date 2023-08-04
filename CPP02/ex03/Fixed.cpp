/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:05:45 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 11:33:36 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_nb = 0;
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}
/*convertie value en virgule fixe => multiplie par 2 eleve a la puissance du
nombre de bits de la partie fractionnaire.*/
Fixed::Fixed(const int value)
{
	this->_nb = value << _bits;
	//std::cout << "Int constructor called" << std::endl;
	return ;
}
/*pareil qu'avec un int sauf qu'on arrondi. virgule flottante arrondie correctement
avant la conversion en virgule fixe.*/
Fixed::Fixed(const float value)
{
	this->_nb = roundf(value * (1 << _bits));
	//std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
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
	//std::cout <<"setRawBits member function called" << std::endl;
	return ;
}
/*divise la _nb par 2 eleve a la puissance du nombre de bits de la partie
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
	{
		//std::cout << "Copy assignment operator called" << std::endl;
		this->_nb = test.getRawBits();
	}
	return (*this);
}

/*surcharge operateur de sortie "<<". Converti ce qu'il y a en in grace a tofloat
et l'affiche sur le flux de sortie out. Lorsque l'on veut afficher un objet, cette surcharge
permet d'afficher comme s'il s'agissait d'un nombre en virgule flottante normal*/
std::ostream &operator<<(std::ostream &out, Fixed const &in)
{
	out << in.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& inst) const
{
	return (this->getRawBits() > inst.getRawBits());
}

bool Fixed::operator<(const Fixed& inst) const
{
	return (this->getRawBits() < inst.getRawBits());
}

bool Fixed::operator>=(const Fixed& inst) const
{
	return (this->getRawBits() >= inst.getRawBits());
}

bool Fixed::operator<=(const Fixed& inst) const
{
	return (this->getRawBits() <= inst.getRawBits());
}

bool Fixed::operator==(const Fixed& inst) const
{
	return (this->getRawBits() == inst.getRawBits());
}

bool Fixed::operator!=(const Fixed& inst) const
{
	return (this->getRawBits() != inst.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &inst) const
{
	return (this->toFloat() + inst.toFloat());
}

Fixed	Fixed::operator-(const Fixed &inst) const
{
	return (this->toFloat() - inst.toFloat());
}

Fixed	Fixed::operator*(const Fixed &inst) const
{
	return (this->toFloat() * inst.toFloat());
}

Fixed	Fixed::operator/(const Fixed &inst) const
{
	return (this->toFloat() / inst.toFloat());
}

/*pre-incrementation*/
Fixed&	Fixed::operator++(void)
{
	++_nb;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--_nb;
	return (*this);
}

/*Post-incrementation*/
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	_nb++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	_nb--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& first, Fixed& second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

Fixed&	Fixed::max(Fixed& first, Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}
