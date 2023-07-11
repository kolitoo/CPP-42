/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:06:07 by abourdon          #+#    #+#             */
/*   Updated: 2023/06/29 15:16:03 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.class.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor Contact called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Destructor Contact called" << std::endl;
	return ;
}

std::string	Contact::_get_contact_infos(std::string str)
{
	std::string	infile_info;

	while (infile_info.empty() == 1)
	{
		std::cout << str;
		std::cin >> infile_info;
	}
	return (infile_info);
}

void	Contact::get_contact(void)
{
	this->contact_infos.first_name = _get_contact_infos("First name => ");
	this->contact_infos.last_name = _get_contact_infos("Last name => ");
	this->contact_infos.nick_name = _get_contact_infos("Nickname => ");
	this->contact_infos.phone_number = _get_contact_infos("Phone number => ");
	this->contact_infos.darkest_secret = _get_contact_infos("Darkest secret => ");
}
