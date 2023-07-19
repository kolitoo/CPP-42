/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:53:39 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/19 17:19:24 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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
				phonebook.search();
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
