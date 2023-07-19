/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:55:45 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/19 17:12:01 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		int			get_index(void) const;
		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phonenumber(void) const;
		std::string	get_darkestsecret(void) const;
		void		set_index(int index);
		void		set_firstname(std::string firstname);
		void		set_lastname(std::string lastname);
		void		set_nickname(std::string nickname);
		void		set_phonenumber(std::string phonenumber);
		void		set_darkestsecret(std::string darkestsecret);
		
	private:
		int			_index;
		std::string		_phonenumber;
		std::string _firstname;
		std::string _lastname;
		std::string	_nickname;
		std::string	_darkestsecret;
};

#endif