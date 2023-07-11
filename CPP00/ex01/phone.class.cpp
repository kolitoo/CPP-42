/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:51:00 by abourdon          #+#    #+#             */
/*   Updated: 2023/06/29 15:28:28 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.class.hpp"

PhoneBook::PhoneBook(void) : _number(0)
{
	std::cout << "Constructor PhoneBook called" << std::endl;
	return ;
	
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor PhoneBook called" << std::endl;
	return ;
}

void	PhoneBook::add(void)
{
	Contact new_contact;

	new_contact.get_contact();
	if (this->_number == 8)
		this->_number = 0;
	new_contact.contact_infos.index = this->_number + '0';
	this->_book[this->_number] = new_contact.contact_infos;
	this->_number++;
}

int	PhoneBook::search(void)
{
	std::string	index;
	
	if (this->_book[0].index.empty() == 1)
	{
		std::cout << "ADD a contact before to search" << std::endl;
		return (0);
	}
	_print_book();
	std::cout << "                 Press Contact Number" << std::endl;
	while (1)
	{
		std::cin >> index;
		if ((index[0] < '0' || index[0] > '7') || _book[index[0] - '0'].first_name.empty() == 1)
			std::cout << "Number contact unknown, press a correct number" << std::endl;
		else
		{
			std::cout << "|-------------------------------------------------------|" << std::endl;
			std::cout << "|      First name:              " << this->_book[index[0] - 48].first_name << std::endl;
			std::cout << "|      Last name:               " <<  this->_book[index[0] - 48].last_name << std::endl;
			std::cout << "|      Nick name:               " << this->_book[index[0] - 48].nick_name << std::endl;
			std::cout << "|      Phone number:            " <<  this->_book[index[0] - 48].phone_number << std::endl;
			std::cout << "|      Darkest_secret:          " <<  this->_book[index[0] - 48].darkest_secret << std::endl;
			std::cout << "|-------------------------------------------------------|" << std::endl;
			break;
		}
	}
	return (0);
}

void	PhoneBook::_print_contact_info(std::string str)
{
	std::cout << "|";
	if (str.size() > 10)
	{
		std::cout << " ";
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
		std::cout << " ";
	}
	else
	{
		for (int j = 0; j < (int)(12 - str.size()) / 2; j++)
			std::cout << " ";
		std::cout << str;
		for (int k = 0; k < (int)(12 - str.size()) / 2; k++)
			std::cout << " ";
		if ((int)(12 - str.size()) % 2 == 1)
			std::cout << " ";
	}
}

void	PhoneBook::_print_book(void)
{
	std::cout << "|-------------------------------------------------------|" << std::endl;
	std::cout << "|   Index    |" << " First name |" << " Last name  |" << "  Nickname      |" << std::endl;
	std::cout << "|-------------------------------------------------------|" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		if (this->_book[i].index.empty() == 1)
			return ;
		_print_contact_info(this->_book[i].index);
		_print_contact_info(this->_book[i].first_name);
		_print_contact_info(this->_book[i].last_name);
		_print_contact_info(this->_book[i].nick_name);
		std::cout << "    |";
		std::cout << std::endl;
		std::cout << "|-------------------------------------------------------|" << std::endl;
	}
	std::cout << std::endl;
}