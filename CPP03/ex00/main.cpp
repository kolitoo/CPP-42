/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/31 14:55:02 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
		ClapTrap	perso1("Jack");
		ClapTrap	perso2("John");
		ClapTrap	perso3 = perso2;

		perso1.attack("John");
		perso2.takeDamage(9);
		perso3.takeDamage(5);
		perso3.beRepaired(5);
}