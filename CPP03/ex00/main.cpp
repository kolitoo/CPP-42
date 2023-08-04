/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:23:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/04 09:23:50 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
		ClapTrap	perso1("Jack");
		ClapTrap	perso2("Leon");
		ClapTrap	perso3 = perso2;

		perso1.attack("Leon");
		perso2.takeDamage(10);
		perso3.takeDamage(5);
		perso3.beRepaired(5);
}