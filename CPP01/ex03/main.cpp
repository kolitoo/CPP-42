/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:23 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/20 11:52:30 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/*L'utilisation d'une référence dans HumanA assure que l'objet Weapon ne peut pas être modifié
une fois que HumanA est créé, tandis que l'utilisation d'un pointeur dans HumanB permet de changer
l'objet Weapon qu'il pointe à tout moment après sa création.*/
int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
