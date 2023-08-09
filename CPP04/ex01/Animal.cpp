/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:03:25 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 10:53:05 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal Constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &copy)
{std::cout << "Animal Copy Constructor called" << std::endl;
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal &substitue)
{
	if (this != &substitue)
		_type = substitue._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "animalllll" << std::endl;
	return ;
}

std::string	Animal::getType() const
{
	return (_type);
}