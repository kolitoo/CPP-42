/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:11 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/21 09:01:50 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	// std::cout << "Harl constructor called" << std::endl;
	return ;
}
Harl::~Harl(void)
{
	// std::cout << "Harl constructor destroyed" << std::endl;
	return ;
}
void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return ;
}
void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
	return ;
}
void	Harl::_warning(void)
{
	std::cout << "[ Warning ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}
void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}
int		Harl::_getlevel(std::string level, std::string *levels)
{
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}
void	Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};

	int i = this->_getlevel(level, levels);
	if (i >= 0 && i <= 3)
	{
		switch (i)
		{
			case 0:
				this->_debug();
			case 1:
				this->_info();
			case 2:
				this->_warning();
			case 3:
				this->_error();
		}
	}
	else
		std::cout << "Write a valid level: \"debug\", \"info\", \"warning\", \"error\"" << std::endl;
}
