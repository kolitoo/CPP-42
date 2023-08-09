/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:49:43 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:36:30 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name): _name(name)
{
	// std::cout << "Character constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		_inventaire[i] = NULL;
}

Character::Character(const Character &copy)
{
	//std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character::~Character(void)
{
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
			delete _inventaire[i];
}

Character	&Character::operator=(const Character &substitue)
{
	if (this != &substitue)
	{
		_name = substitue._name;
		for (int i = 0; i < 4; i++)
			delete _inventaire[i];
		for (int i = 0; i < 4; i++)
			_inventaire[i] = substitue._inventaire[i]->clone();
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	int i = 0;

	if (m != NULL)
	{
		while (i < 4 && _inventaire[i] != NULL)
			i++;
		if (i == 4)
			std::cout << "inventaire is full" << std::endl;
		else
			_inventaire[i] = m;
	}
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && _inventaire[idx] != NULL)
		_inventaire[idx] = NULL;
	else
		std::cout << "Wrong index or inventaire already NULL" << std::endl;
	return ;
}

void	Character::use(int idc, ICharacter &target)
{
	if (idc < 4 && idc >= 0 && _inventaire[idc] != NULL)
		_inventaire[idc]->use(target);
	else
		std::cout << "No Materia in this index" << std::endl;
	return ;
}
