/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:12 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 10:49:18 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : _weaponB(NULL), _name(str)
{
	std::cout << this->_name << " created without weapon " << std::endl;
	return ;
}

HumanB::HumanB(std::string str, Weapon *weaponB) : _weaponB(weaponB), _name(str)
{
	std::cout << this->_name << " created with " << this->_weaponB->getType() << std::endl;
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
//Obliger d'avoir une fonction en plus de HumanA set car on ne doit pas init dans le constructeur ici.
//On utilise ici un poiteur car HUmanB n'est pas obliger d'avoir une arme des le debut, ON est donc obliger d'utiliser un poiteur
//Car on a pas besoin d'avoir une instance existante pour creer un poiteur contrairement a une reference
void	HumanB::setWeapon(Weapon &weaponB)
{
	this->_weaponB = &weaponB;
}