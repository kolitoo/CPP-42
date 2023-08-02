/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/02 15:23:27 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// int	main(void)
// {
// 	DiamondTrap	perso1("Jack");
// 	DiamondTrap	perso2("John");
// 	DiamondTrap	perso3 = perso2;

// 	perso1.attack("John");
// 	perso2.takeDamage(9);
// 	perso3.takeDamage(5);
// 	perso3.beRepaired(5);
// }

int	main(void)
{
	DiamondTrap	Diam("Diam");
	
	Diam.print_info();
	Diam.whoAmI();
	Diam.beRepaired(1);
	Diam.attack("Lucas");//Ici on utilisera de base la fonction de ScavTrap
	// Diam.ClapTrap::attack("Paul");//Ici si on souhaite grace a l'operateur de resolution de portee on peut utiliser attck de ClapTrap
	Diam.guardGate();
	Diam.highFivesGuys();
	return (0);
}