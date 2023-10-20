/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:45:17 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/20 10:45:07 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*test = NULL;
	int	nb = 0;
	test = test->zombieHorde(nb, "Bernard");
	for (int i = 0; i < nb; i++)
		test->announce();
	delete []test;//et pas "delete test[nb]" car on ne veut pas liberer un element specifique mais tt le tableau
}