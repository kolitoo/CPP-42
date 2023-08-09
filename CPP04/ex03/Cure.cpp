/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:24:33 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:33:15 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	_type = "cure";
	//std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy): AMateria("cure")
{
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure::~Cure(void)
{
	//std::cout << "Cure destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const& substitue)
{
	if (this != &substitue)
	{
		_type = substitue._type;
	}
	return (*this);
}

AMateria	*Cure::clone() const
{
	AMateria	*clone = new Cure(*this);
	return (clone);
}

void		Cure::use(ICharacter& target)
{
	std::cout << "Cure : \"*heals " << target.getName() << "'s wounds *\"" << std::endl;
	return ;
}