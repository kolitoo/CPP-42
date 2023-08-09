/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:11:33 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 10:13:51 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	_type = "Wrongcat";
	std::cout << "WrongCat Constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &substitue)
{
	if (this != &substitue)
		_type = substitue._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongMiaou" << std::endl;
	return ;
}