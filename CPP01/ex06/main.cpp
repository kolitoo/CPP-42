/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:17:59 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/19 14:22:56 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl h;
	if (ac == 2)
		h.complain(av[1]);
	else
		std::cout << "Wrong arguments numbers" << std::endl;
}