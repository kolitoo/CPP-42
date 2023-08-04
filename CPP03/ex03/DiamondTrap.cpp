/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:22:27 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:48:35 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_life_point = 100;
	_energy_point = 50;
	_attack_dmg = 30;
	std::cout << "Constructor DiamondTrap " << _name << " called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "Constructor DiamondTrap copy " << _name << " called" << std::endl;
	return ; 
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor DiamondTrap " << _name << " called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: " << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::print_info(void)
{
	std::cout << "DiamondTrap infos: " << std::endl;
	std::cout << "name: " <<  _name << std::endl;
	std::cout << "life point: " << _life_point << std::endl;
	std::cout << "energy points: " << _energy_point << std::endl;
	std::cout << "attack damage: " << _attack_dmg << std::endl;
	return ;
}