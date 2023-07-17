/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:12 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 16:57:46 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : _weaponB(NULL), _name(str)
{
	std::cout << this->_name << " created without weapon " << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "Constructor " << this->_name << " destroyed" << std::endl;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponB)
{
	this->_weaponB = &weaponB;
}