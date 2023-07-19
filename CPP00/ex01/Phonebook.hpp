/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:24:08 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/19 17:34:20 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <ios>
#include <iostream>
#include "Contact.hpp"

class	PhoneBook
{
	public:
	
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);

	private:
		Contact _Contact[8];
		std::string	find_put_info(std::string info);
		void	_print_book(void);
		int	_i;
		
};

# endif