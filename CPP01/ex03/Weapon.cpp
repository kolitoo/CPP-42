/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:29 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/20 11:39:37 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->_type = str;
	// std::cout << "Constructor Weapon created" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	// std::cout << "Constructor Weapon destroyed" << std::endl;
	return ;
}

std::string const	&Weapon::getType(void)
{
	std::string const &typeREF = this->_type;
	return (typeREF);
}

void	Weapon::setType(std::string str)
{
	this->_type = str;
}