/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:44:59 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:33:08 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
{
	_type = type;
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const& copy)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void)
{
	//std::cout << "AMateria destructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const& substitue)
{
	if (this != &substitue)
	{
		_type = substitue._type;
	}
	return (*this);
}

std::string const& 	AMateria::getType() const
{
	return (_type);
}

void		AMateria::use(ICharacter& target)
{
	std::cout << "Materia use on " << target.getName() << std::endl;
	return ;
}