/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:44:44 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/19 17:35:15 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Contact constructor destroyed" << std::endl;
	return ;
}
/*-----GET------*/
int	Contact::get_index(void) const
{
	return (this->_index);
}

std::string	Contact::get_phonenumber(void) const
{
	return (this->_phonenumber);
}

std::string	Contact::get_firstname(void) const
{
	return (this->_firstname);
}

std::string	Contact::get_lastname(void) const
{
	return (this->_lastname);
}
std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_darkestsecret(void) const
{
	return (this->_darkestsecret);
}

/*------SET-----*/
void	Contact::set_index(int index)
{
	this->_index = index;
	return ;
}

void	Contact::set_firstname(std::string firstname)
{
	this->_firstname = firstname;
	return ;
}
void	Contact::set_lastname(std::string lastname)
{
	this->_lastname = lastname;
	return ;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}

void	Contact::set_phonenumber(std::string phonenumber)
{
		this->_phonenumber = phonenumber;
	return ;
}

void	Contact::set_darkestsecret(std::string darkestsecret)
{
	this->_darkestsecret = darkestsecret;
	return ;
}

