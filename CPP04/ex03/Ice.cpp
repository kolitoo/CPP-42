/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:16:26 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:33:20 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void):AMateria("ice")
{
	_type = "ice";
	//std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy):AMateria("ice")
{
	//std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice::~Ice(void)
{
	//std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const& substitue)
{
	if (this != &substitue)
	{
		_type = substitue._type;
	}
	return (*this);
}

AMateria	*Ice::clone() const
{
	AMateria	*clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter& target)
{
	std::cout << "Ice : \"* shoots an ice bolt at " << target.getName() << "*\""<< std::endl;
	return ;
}