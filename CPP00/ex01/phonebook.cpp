/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:22:47 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/20 11:16:05 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void):_i(0)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook constructor destroyed" << std::endl;
	return ;
}

std::string	PhoneBook::find_put_info(std::string info)
{
	std::string	infile_info;
	
	while (infile_info.empty() == 1)
	{
		std::cout << info;
		std::cin >> infile_info;
	}
	return (infile_info);
}

void	PhoneBook::add(void)
{
	if (this->_i == 8)
		this->_i = 0;
	this->_Contact[this->_i].set_index(this->_i);
	this->_Contact[this->_i].set_firstname(this->find_put_info("First Name ? "));
	this->_Contact[this->_i].set_lastname(this->find_put_info("Last Name ? "));
	this->_Contact[this->_i].set_nickname(this->find_put_info("Nick Name ? "));
	this->_Contact[this->_i].set_phonenumber(this->find_put_info("Phone Number ? "));
	this->_Contact[this->_i].set_darkestsecret(this->find_put_info("Darkest Secret ? "));
	std::cout << "Contact " << this->_Contact[this->_i].get_firstname() << " added" << std::endl;
	this->_i++;
	return ;
}

void	PhoneBook::_print_contact_info(std::string const str) const
{
	std::cout << "|";
	if (str.size() > 10)
		std::cout << str.substr(0,9) << ".";
	else if (str.size() == 10)
		std::cout << str;
	else
		std::cout << std::setw(10) << str;
}

void	PhoneBook::_print_book(void) const
{
	for(int i = 0; i < 8; i++)
	{
		if (this->_Contact[i].get_firstname().empty() == 1)
			return ;
		std::cout << "|" << std::setw(9) << this->_Contact[i].get_index();
		this->_print_contact_info(this->_Contact[i].get_firstname());
		this->_print_contact_info(this->_Contact[i].get_lastname());
		this->_print_contact_info( this->_Contact[i].get_nickname());
	 	std::cout << "|\n";
	}
}

void	PhoneBook::search(void)
{
	std::string index;
	if (this->_Contact[0].get_firstname().empty() == 1)
	{
		std::cout << "ADD a contact before to search" << std::endl;
		return ;
	}
	this->_print_book();
	std::cout << "|            Press Contact Number" << std::setw(11) << "|" << std::endl;
	while (1)
	{
		std::cin >> index;
		if ((index[0] < '0' || index[0] > '7') || this->_Contact[index[0] - '0'].get_firstname().empty() == 1)
			std::cout << "Number contact unknown, press a correct number" << std::endl;
		else
		{
			std::cout << "|------------------------------------------|" << std::endl;
			std::cout << "   First name:             " << this->_Contact[index[0] - 48].get_firstname() << std::endl;
			std::cout << "   Last name:              " <<  this->_Contact[index[0] - 48].get_lastname() << std::endl;
			std::cout << "   Nick name:              " << this->_Contact[index[0] - 48].get_nickname() << std::endl;
			std::cout << "   Phone number:           " <<  this->_Contact[index[0] - 48].get_phonenumber() << std::endl;
			std::cout << "   Darkest_secret:         " <<  this->_Contact[index[0] - 48].get_darkestsecret() << std::endl;
			std::cout << "|------------------------------------------|" << std::endl;
			break;
		}
	}
	return ;
}