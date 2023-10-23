/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:45:17 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/23 10:56:32 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde = NULL;
	int	nb = 5;
	if (nb < 0)
		return (1);
	horde = horde->zombieHorde(nb, "Bernard");
	for (int i = 0; i < nb; i++)
		horde->announce();
	delete []horde;//et pas "delete horde[nb]" car on ne veut pas liberer un element specifique mais tt le tableau
	return (0);
}