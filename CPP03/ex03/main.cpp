/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:47:19 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	perso1("Jack");
	DiamondTrap	perso2("Leon");
	DiamondTrap	perso3 = perso2;

	perso1.whoAmI();
	perso1.attack("John");
	perso2.takeDamage(100);
	perso3.takeDamage(5);
	perso3.beRepaired(5);
	perso3.guardGate();
	perso3.highFivesGuys();
}
