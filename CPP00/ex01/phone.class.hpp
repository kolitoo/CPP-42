/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:24:08 by abourdon          #+#    #+#             */
/*   Updated: 2023/06/29 11:48:43 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONE_CLASS_HPP
#define PHONE_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

struct contact_struct{

	std::string	index;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

};

class	PhoneBook
{
	public:


		PhoneBook(void);
		~PhoneBook(void);
		
		void	add(void);
		int	search(void);
		
	private:
		int _number;
		contact_struct _book[8];
		
		void	_print_contact_info(std::string str);
		void	_print_book(void);
	
};

class	Contact
{
	public:

		contact_struct contact_infos;

		Contact(void);
		~Contact(void);
		
		void	get_contact(void);
		
	private:

		std::string	_get_contact_infos(std::string message);
	
};

# endif