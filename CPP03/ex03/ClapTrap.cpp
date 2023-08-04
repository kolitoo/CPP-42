/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:24:15 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:45:09 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string nom):_name(nom), _life_point(10), _energy_point(10) ,_attack_dmg(0)
{
	std::cout << "Constructor ClapTrap " << _name << " called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Constructor ClapTrap copy " << _name << " called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor ClapTrap of " << _name << " called" << std::endl;
	return ;
}

ClapTrap 	&ClapTrap::operator=(const ClapTrap &substitue)
{
	if (this != &substitue)
	{
		_name = substitue._name + "_copy";
		_life_point = substitue._life_point;
		_energy_point = substitue._energy_point;
		_attack_dmg = substitue._attack_dmg;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_point > 0)
	{
		_life_point -= _attack_dmg;
		_energy_point--;
		std::cout << "ClapTrap: " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage !" << std::endl;
	}
	else
		std::cout << "ClapTrap: " << "u have 0 energy point" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_life_point - amount > 0)
	{
		_life_point -= amount;
		std::cout << "ClapTrap: " << _name << " took " << amount << " points of damage !" << std::endl;
	}
	else
	{
		_life_point = 0;
		std::cout << "ClapTrap: " << _name << " is dead with 0 life point" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_point > 0)
	{
		_life_point += amount;
		_energy_point--;
		std::cout << "ClapTrap: " << _name << " repaired " << amount << " points of life !" << std::endl;
	}
	else
		std::cout << "ClapTrap: " << "u have 0 energy point" << std::endl;
	return ;
}