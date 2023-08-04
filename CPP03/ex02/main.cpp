/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:44:05 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	perso1("Jack");
	FragTrap	perso2("Leon");
	FragTrap	perso3 = perso2;

	//perso1.print_info();
	perso1.attack("John");
	perso2.takeDamage(100);
	perso3.takeDamage(5);
	perso3.beRepaired(5);
	perso1.highFivesGuys();
}