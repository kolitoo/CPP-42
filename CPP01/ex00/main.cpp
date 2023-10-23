/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:21 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/23 10:52:21 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *test = NULL;
	test = test->newZombie("OnTheHeap");//new pour la heap pour pouvoir utiliser hors de la portee du programme
	test->announce();
	test->randomChump("OnTheStack");//sur la stack mais on peut utiliser que dans une partie du programme
	delete test;
}