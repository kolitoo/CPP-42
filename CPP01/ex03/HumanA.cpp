/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:17 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 16:33:13 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weaponA) : _weaponA(weaponA), _name(str)
{
	std::cout << this->_name << " created with " << this->_weaponA.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "Constructor " << this->_name << " destroyed" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks With their " << this->_weaponA.getType() << std::endl;
}