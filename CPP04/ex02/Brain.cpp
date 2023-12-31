/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:51:24 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/27 10:07:45 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &substitue)
{
	if (this != &substitue)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = substitue._ideas[i];
	}
	return (*this);
}
