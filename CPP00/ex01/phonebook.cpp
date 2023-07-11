/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:22:47 by abourdon          #+#    #+#             */
/*   Updated: 2023/06/29 11:49:34 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.class.hpp"

int	main(int ac, char **av)
{
	(void)av;

	if (ac == 1)
	{
		PhoneBook phonebook;
		std::string	input;
		while(1)
		{
			std::cin >> input;
			if (input == "EXIT")
				return (1) ;
			else if (input == "ADD")
				phonebook.add();
			else if (input == "SEARCH")
			{
				if (phonebook.search() == 1)
					return (1);
			}
			else
			{
				std::cout << "Press ADD to add a contact" << std::endl;
				std::cout << "Press SEARCH to search a contact" << std::endl;
				std::cout << "Press EXIT to quit" << std::endl;
			}
		}
	}
	else
		std::cout << "Only one argument requiered: \"./phonebook\"" << std::endl;
	return (0) ;
}
