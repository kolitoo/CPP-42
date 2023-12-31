/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:31:52 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 17:32:24 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	_type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog &substitue)
{
	if (this != &substitue)
		_type = substitue._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
	return ;
}
