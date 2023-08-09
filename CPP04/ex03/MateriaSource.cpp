/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:05:56 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:41:38 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	//std::cout << "MateriaSource constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		_mat_tab[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	//std::cout << "AMateria destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
			delete _mat_tab[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &substitue)
{
	if (this != &substitue)
	{
		for (int i = 0; i < 4; i++)
			delete _mat_tab[i];
		for (int i = 0; i < 4; i++)
			_mat_tab[i] = substitue._mat_tab[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* mat)
{
	int i = 0;

	if (mat != NULL)
	{
		while (i < 4 && _mat_tab[i] != NULL)
			i++;
		if (i == 4)
			std::cout << "Materia stock is full" << std::endl;
		else
			_mat_tab[i] = mat;
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	int i = 0;

	while (i < 4)
	{
		if (_mat_tab[i] != NULL && _mat_tab[i]->getType() == type)
			break;
		i++;
	}
	if (i == 4)
		return (NULL);
	return (_mat_tab[i]->clone());
}