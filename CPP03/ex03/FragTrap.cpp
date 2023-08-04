/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:05:59 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:50:03 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_life_point = 100;
	_energy_point = 100;
	_attack_dmg = 30;
	std::cout << "Constructor FragTrap " << _name << " called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "Constructor FragTrap copy " << _name << " called" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor FragTrap " << _name << " called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << _name << " does a high fives" << std::endl;
	return ;
}

void	FragTrap::print_info(void)
{
	std::cout << "FragTrap infos: " << std::endl;
	std::cout << "name: " <<  _name << std::endl;
	std::cout << "liefe point: " << _life_point << std::endl;
	std::cout << "energy points: " << _energy_point << std::endl;
	std::cout << "attack damage: " << _attack_dmg << std::endl;
	return ;
}
