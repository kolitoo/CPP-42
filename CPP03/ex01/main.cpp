/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/02 13:44:35 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
		ScavTrap	perso1("Jack");
		ScavTrap	perso2("John");
		ScavTrap	perso3 = perso2;

		perso1.print_info();
		perso1.attack("John");
		perso1.guardGate();
		perso2.takeDamage(9);
		perso3.takeDamage(5);
		perso3.beRepaired(5);
}