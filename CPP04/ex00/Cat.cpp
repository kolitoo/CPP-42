/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:06:47 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 17:31:48 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	_type = "cat";
	std::cout << "Cat Constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat &substitue)
{
	if (this != &substitue)
		_type = substitue._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
	return ;
}
