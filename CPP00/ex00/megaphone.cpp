/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:49:08 by abourdon          #+#    #+#             */
/*   Updated: 2023/06/27 14:31:04 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		for (int j = 1; j < ac; j++)
		{
			std::string str;
			str = av[j];
			for (int i = 0; str[i] != '\0'; i++)
				str[i] = toupper(str[i]);
			std::cout << str;
			if (j < ac - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
