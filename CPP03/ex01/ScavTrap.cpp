/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:41:01 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:37:28 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_life_point = 100;
	_energy_point = 50;
	_attack_dmg = 20;
	std::cout << "Constructor ScavTrap " << _name << " called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "Constructor ScavTrap copy " << _name << " called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap " << _name << " called" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << _name << " entered in Gate keeper mod" << std::endl;	
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy_point > 0)
	{
		_energy_point--;
		std::cout << "ScavTrap: " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage !" << std::endl;
	}
	else
		std::cout << "ScavTrap: " << "u have 0 energy point" << std::endl;
	return ;
}

void	ScavTrap::print_info(void)
{
	std::cout << "ScrapTrap infos: " << std::endl;
	std::cout << "name: " <<  _name << std::endl;
	std::cout << "liefe point: " << _life_point << std::endl;
	std::cout << "energy points: " << _energy_point << std::endl;
	std::cout << "attack damage: " << _attack_dmg << std::endl;
	return ;
}
