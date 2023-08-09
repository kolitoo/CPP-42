/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:03:25 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 11:53:21 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void): _type("AAnimal")
{
	std::cout << "AAnimal Constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &copy)
{std::cout << "AAnimal Copy Constructor called" << std::endl;
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Destructor called" << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal &substitue)
{
	if (this != &substitue)
		_type = substitue._type;
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimalllll" << std::endl;
	return ;
}

std::string	AAnimal::getType() const
{
	return (_type);
}