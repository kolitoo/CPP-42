/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:06:47 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/27 10:07:20 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal()
{
	std::cout << "Cat Constructor called" << std::endl;
	_type = "cat";
	_Brain = new Brain();
	return ;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	_type = copy._type;
	_Brain = new Brain(*copy._Brain);
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _Brain;
	return ;
}

Cat	&Cat::operator=(const Cat &substitue)
{
	if (this != &substitue)
	{
		_type = substitue._type;
		delete _Brain;
		_Brain = new Brain(*substitue._Brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
	return ;
}
